/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:20:58 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 04:21:00 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_export(t_shell *shell, t_prompt *prompt)
{
	if (count_words(prompt->cmd_line) == 1)
		write_export(shell->export_lines);
	else
		add_lines(shell, prompt);
}

void	exec_unset(t_shell *shell, t_prompt *prompt)
{
	int		i;

	i = 1;
	while (prompt->strs[i])
	{
		remove_line(&shell->env_lines, prompt->strs[i]);
		remove_line(&shell->export_lines, prompt->strs[i]);
		i = i + 1;
	}
}

void	exec_setenv(t_shell *shell, t_prompt *prompt)
{
	char	**split_var;
	char	*var;
	char	*value;
	char	*new_line;

	if (prompt->strs[1] == NULL)
		return;
	if (ft_strchr(prompt->strs[1], '=') == NULL)
		return;
	split_var = ft_split(prompt->strs[1], '=');
	if (split_var == NULL)
		return;
	var = split_var[0];
	value = split_var[1];
	new_line = ft_strjoin(var, "=");
	new_line = ft_strjoin2(2, (char *[]){new_line, value}, "");
	(void)new_line;
	if (ft_strcmp(var, "PATH") == 0)
	{
		if (shell->splitted_path != NULL)
			free_2d_array(shell->splitted_path);
		shell->splitted_path = split_path_from_value(value);
	}
	free_2d_array(split_var);
}

void	exec_unsetenv(t_shell *shell, t_prompt *prompt)
{
	if (prompt->strs[1] == NULL)
		return;
	remove_line(&shell->env_lines, prompt->strs[1]);
	remove_line(&shell->export_lines, prompt->strs[1]);
	if (ft_strcmp(prompt->strs[1], "PATH") == 0)
	{
		if (shell->splitted_path != NULL)
		{
			free_2d_array(shell->splitted_path);
			shell->splitted_path = NULL;
		}
	}
}

void	execute_builtin(t_shell *shell, t_prompt *prompt)
{
	if (!ft_strlen(prompt->cmd_line) || !count_strings(prompt->strs))
		ft_printf("");
	else if (ft_strcmp(prompt->strs[0], "echo") == 0)
		exec_echo(prompt);
	else if (ft_strcmp(prompt->strs[0], "export") == 0)
		exec_export(shell, prompt);
	else if (ft_strcmp(prompt->strs[0], "env") == 0 && !prompt->strs[1])
		write_env(shell->env_lines);
	else if (ft_strcmp(prompt->strs[0], "cd") == 0)
		exec_cd(shell, prompt);
	else if (ft_strcmp(prompt->strs[0], "pwd") == 0 && !prompt->strs[1])
		ft_printf("%s\n", shell->pwd);
	else if (ft_strcmp(prompt->strs[0], "unset") == 0 && prompt->strs[1])
		exec_unset(shell, prompt);
	else if (ft_strcmp(prompt->strs[0], "exit") == 0 && !prompt->strs[1])
		exec_exit();
	else if (!existing_command(shell->splitted_path, prompt->strs[0])
		&& ft_strcmp(prompt->strs[0], "history") != 0)
		ft_printf("command not found: %s\n", prompt->strs[0]);
}
