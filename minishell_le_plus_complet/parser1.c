/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:46:46 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 03:46:47 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int count_raw_cmds(char **raw_cmds)
{
	int count;

	count = 0;
	while (raw_cmds[count])
	{
		count = count + 1;
	}
	return (count);
}

static char **remove_hd_tokens(char **tokens, char **heredoc)
{
	int i;
	int new_count;
	char **new_tokens;

	i = 0;
	new_count = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "<<") == 0)
		{
			i = i + 2;
		}
		else
		{
			new_count = new_count + 1;
			i = i + 1;
		}
	}
	new_tokens = malloc(sizeof(char *) * (new_count + 1));
	if (!new_tokens)
		return (NULL);
	i = 0;
	new_count = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "<<") == 0)
		{
			*heredoc = ft_strdup(tokens[i + 1]);
			i = i + 2;
		}
		else
		{
			new_tokens[new_count] = ft_strdup(tokens[i]);
			new_count = new_count + 1;
			i = i + 1;
		}
	}
	new_tokens[new_count] = NULL;
	return (new_tokens);
}

t_command *parse_command(char *raw)
{
	t_command *cmd;
	char **tokens;
	char *heredoc;

	cmd = malloc(sizeof(t_command));
	if (cmd == NULL)
		return (NULL);
	tokens = advanced_tokenize(raw);
	heredoc = NULL;
	tokens = remove_hd_tokens(tokens, &heredoc);
	cmd->args = tokens;
	cmd->heredoc_delim = heredoc;
	return (cmd);
}
