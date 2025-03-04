/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:49:04 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 03:49:05 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_2d_array(char **strs)
{
	int i;

	i = 0;
	if (!strs)
		return;
	while (strs[i])
	{
		free(strs[i]);
		i = i + 1;
	}
	free(strs);
}

void free_prompt(t_prompt *prompt)
{
	if (prompt)
	{
		free(prompt->cmd_line);
		free_2d_array(prompt->strs);
		free(prompt);
	}
}

void free_terminal(t_shell *shell)
{
	free(shell->path);
	free(shell->home_path);
	free(shell->pwd);
	free(shell->old_pwd);
	free_2d_array(shell->splitted_path);
	free_2d_array(shell->env);
	ft_lstclear(&shell->env_lines, free);
	ft_lstclear(&shell->export_lines, free);
	free(shell);
}
