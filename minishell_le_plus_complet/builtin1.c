/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:20:37 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 04:20:38 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cd(t_shell *shell, t_prompt *prompt)
{
	int		ret;
	char	buffer[PATH_MAX];

	ret = chdir(prompt->strs[1]);
	if (ret != 0)
	{
		ft_printf("cd: no such file or directory: %s\n", prompt->strs[1]);
	}
	else
	{
		if (ft_strcmp(shell->old_pwd, shell->pwd) != 0)
		{
			free(shell->old_pwd);
			shell->old_pwd = ft_strdup(shell->pwd);
		}
		getcwd(buffer, PATH_MAX);
		free(shell->pwd);
		shell->pwd = ft_strdup(buffer);
	}
	update_paths(shell, shell->env_lines);
	update_paths_export(shell, shell->export_lines);
}

void	exec_echo(t_prompt *prompt)
{
	char	*msg;

	msg = ft_strjoin2(prompt->nb_args - 2, prompt->strs + 2, " ");
	ft_printf("%s", msg);
	free(msg);
}

void	exec_exit(void)
{
	write(2, "exit\n", 5);
	exit(1);
}
