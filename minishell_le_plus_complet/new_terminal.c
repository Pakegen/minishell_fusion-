/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_terminal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: votre_nom <votre.email@exemple.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:00:00 by votre_nom        #+#    #+#             */
/*   Updated: 2025/03/04 10:00:00 by votre_nom       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*init_shell(char **envp)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (shell == NULL)
		return (NULL);
	shell->path = find_path_line(envp);
	shell->old_pwd = get_pwd(envp);
	shell->pwd = get_pwd(envp);
	shell->splitted_path = split_path(envp);
	shell->shlvl = get_shell_level(envp);
	shell->env_lines = NULL;
	copy_env(&shell->env_lines, envp);
	shell->export = get_lines_export(envp);
	sort_strings(shell->export, count_strings(envp));
	copy_export(shell);
	shell->var_names = get_var_names(envp);
	shell->vars = NULL;
	copy_env(&shell->vars, shell->var_names);
	return (shell);
}

t_prompt	*init_prompt(const char *buffer)
{
	t_prompt	*prompt;

	prompt = malloc(sizeof(t_prompt));
	if (prompt == NULL)
		return (NULL);
	prompt->cmd_line = ft_strdup(buffer);
	prompt->strs = ft_split(buffer, ' ');
	prompt->nb_args = count_strings(prompt->strs);
	return (prompt);
}
