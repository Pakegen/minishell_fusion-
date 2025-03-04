/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:47:37 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 04:31:01 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_cd(t_shell *shell, t_prompt *prompt)
{
	int ret;
	char buffer[PATH_MAX];

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

char *get_command_path(char *cmd, char **env)
{
	char *path_line;
	char **paths;
	char *full_path;
	int i;

	if (ft_strchr(cmd, '/') != NULL)
		return (ft_strdup(cmd));
	path_line = find_path_line(env);
	paths = ft_split(path_line, ':');
	free(path_line);
	i = 0;
	full_path = NULL;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], cmd);
		if (access(full_path, F_OK | X_OK) == 0)
			break;
		free(full_path);
		full_path = NULL;
		i = i + 1;
	}
	free_2d_array(paths);
	if (!full_path)
		full_path = ft_strdup(cmd);
	return (full_path);
}
