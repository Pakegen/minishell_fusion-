/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_tokeniser1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:45:16 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 03:45:17 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *append_char(char *str, char c)
{
	int i;
	int len;
	char *new_str;

	if (str)
	{
		len = ft_strlen(str);
	}
	else
	{
		len = 0;
	}
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		new_str[i] = str[i];
		i = i + 1;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	if (str)
		free(str);
	return (new_str);
}

void process_default(char c, t_state *state, char **curr)
{
	if (c == ' ' || c == '\t')
		return;
	if (c == '\'')
	{
		*state = STATE_IN_SINGLE;
		return;
	}
	if (c == '"')
	{
		*state = STATE_IN_DOUBLE;
		return;
	}
	if (c == '\\')
	{
		*state = STATE_ESCAPING;
		return;
	}
	*curr = append_char(*curr, c);
}

void process_in_single(char c, t_state *state, char **curr)
{
	if (c == '\'')
		*state = STATE_DEFAULT;
	else
		*curr = append_char(*curr, c);
}

void process_in_double(char c, t_state *state, char **curr)
{
	if (c == '"')
		*state = STATE_DEFAULT;
	else if (c == '\\')
		*state = STATE_ESCAPING;
	else
		*curr = append_char(*curr, c);
}

void process_escaping(char c, t_state *state, char **curr)
{
	*curr = append_char(*curr, c);
	*state = STATE_DEFAULT;
}
