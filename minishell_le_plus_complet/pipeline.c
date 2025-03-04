/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:46:37 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 03:46:38 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void create_pipe_block(int i, int cmd_count, int pipe_fd[2])
{
	if (i < cmd_count - 1)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		pipe_fd[0] = -1;
		pipe_fd[1] = -1;
	}
}

static void setup_heredoc(int i, t_pipeline *pipeline)
{
	int hd_fd;

	if (pipeline->commands[i].heredoc_delim)
	{
		hd_fd = handle_heredoc(pipeline->commands[i].heredoc_delim);
		if (hd_fd == -1)
		{
			perror("heredoc");
			exit(EXIT_FAILURE);
		}
		if (dup2(hd_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 heredoc");
			exit(EXIT_FAILURE);
		}
		close(hd_fd);
	}
}

static void setup_child(int i, int prev_fd, int pipe_fd[2], t_exec_context *ctx)
{
	char *cmd_path;

	if (i != 0)
	{
		if (dup2(prev_fd, STDIN_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(prev_fd);
	}
	setup_heredoc(i, ctx->pipeline);
	if (i < ctx->cmd_count - 1)
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	cmd_path = get_command_path(ctx->pipeline->commands[i].args[0], ctx->env);
	execve(cmd_path, ctx->pipeline->commands[i].args, ctx->env);
	perror("execve");
	free(cmd_path);
	exit(EXIT_FAILURE);
}

static int handle_fork_and_update(int i, int prev_fd, int pipe_fd[2], t_exec_context *ctx)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		setup_child(i, prev_fd, pipe_fd, ctx);
	if (prev_fd != -1)
		close(prev_fd);
	if (i < ctx->cmd_count - 1)
	{
		prev_fd = pipe_fd[0];
		close(pipe_fd[1]);
	}
	waitpid(pid, NULL, 0);
	return (prev_fd);
}

void execute_pipeline(t_pipeline *pipeline, char **env)
{
	int i;
	int prev_fd;
	int pipe_fd[2];
	t_exec_context ctx;

	ctx.pipeline = pipeline;
	ctx.env = env;
	ctx.cmd_count = pipeline->count;
	prev_fd = -1;
	i = 0;
	while (i < ctx.cmd_count)
	{
		create_pipe_block(i, ctx.cmd_count, pipe_fd);
		prev_fd = handle_fork_and_update(i, prev_fd, pipe_fd, &ctx);
		i = i + 1;
	}
	if (prev_fd != -1)
		close(prev_fd);
}
