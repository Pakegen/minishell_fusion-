/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:23:07 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 04:23:09 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_strings_local(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i = i + 1;
	}
	return (i);
}

static char	*trim_line(const char *line)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	start = 0;
	while (line[start] == ' ' || line[start] == '\t')
	{
		start = start + 1;
	}
	end = ft_strlen(line);
	while (end > start && (line[end - 1] == ' ' || line[end - 1] == '\t'))
	{
		end = end - 1;
	}
	trimmed = malloc(end - start + 1);
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed[i] = line[start];
		i = i + 1;
		start = start + 1;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

static void	execute_semicolons(char *line, char **env)
{
	char		**cmds;
	int			num_cmds;
	int			i;
	char		*trimmed;
	t_pipeline	*pipeline;

	cmds = ft_split(line, ';');
	num_cmds = count_strings_local(cmds);
	i = 0;
	while (i < num_cmds)
	{
		trimmed = trim_line(cmds[i]);
		if (trimmed && ft_strlen(trimmed) > 0)
		{
			pipeline = parse_input(trimmed);
			if (pipeline)
			{
				execute_pipeline(pipeline, env);
				free_pipeline(pipeline);
			}
		}
		if (trimmed)
			free(trimmed);
		i = i + 1;
	}
	free_2d_array(cmds);
}

int	is_valid(char *cmd_line)
{
	int	s_quote_count;
	int	d_quote_count;

	s_quote_count = count_occurrences(cmd_line, '\'');
	d_quote_count = count_occurrences(cmd_line, '"');
	if (s_quote_count % 2 != 0 || d_quote_count % 2 != 0)
		return (0);
	return (1);
}

void	parse_command_line(char *line, char **env)
{
	int	valid;

	valid = is_valid(line);
	if (valid == 0)
	{
		ft_printf("syntax error: unclosed quotes\n");
		line[0] = '\0';
		return;
	}
	if (ft_strchr(line, ';'))
	{
		execute_semicolons(line, env);
		line[0] = '\0';
	}
}
