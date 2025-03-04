/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:48:34 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 03:48:35 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_setenv(t_shell *shell, t_prompt *prompt)
{
	char **split_var;
	char *var;
	char *value;
	char *new_line;

	if (!prompt->strs[1])
		return;
	if (!ft_strchr(prompt->strs[1], '='))
		return;
	split_var = ft_split(prompt->strs[1], '=');
	if (!split_var)
		return;
	var = split_var[0];
	value = split_var[1];
	new_line = ft_strjoin(var, "=");
	new_line = ft_strjoin2(2, (char *[]){new_line, value}, "");
	(void)new_line;
	if (ft_strcmp(var, "PATH") == 0)
	{
		if (shell->splitted_path)
			free_2d_array(shell->splitted_path);
		shell->splitted_path = split_path_from_value(value);
	}
	free_2d_array(split_var);
}

void exec_unsetenv(t_shell *shell, t_prompt *prompt)
{
	if (!prompt->strs[1])
		return;
	remove_line(&shell->env_lines, prompt->strs[1]);
	remove_line(&shell->export_lines, prompt->strs[1]);
	if (ft_strcmp(prompt->strs[1], "PATH") == 0)
	{
		if (shell->splitted_path)
		{
			free_2d_array(shell->splitted_path);
			shell->splitted_path = NULL;
		}
	}
}
