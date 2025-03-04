/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:45:05 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 03:45:06 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char	*line;
	t_pipeline	*pipeline;
	t_shell	*shell;

	(void)argc;
	(void)argv;
	shell = init_shell(env);
	setup_signal();
	while (1)
	{
		line = readline("minishell> ");
		if (line == NULL)
		{
			write(1, "exit\n", 5);
			break;
		}
		if (line[0] != '\0')
			add_history(line);
		parse_command_line(line, env);
		if (line[0] != '\0')
		{
			pipeline = parse_input(line);
			if (pipeline != NULL)
			{
				execute_pipeline(pipeline, env);
				free_pipeline(pipeline);
			}
		}
		free(line);
	}
	free_terminal(shell);
	return (0);
}
