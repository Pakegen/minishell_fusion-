/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:50:23 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 03:50:24 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env *new_line(char *env_line)
{
	int i;
	t_env *new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	i = 0;
	while (env_line[i] && env_line[i] != '=')
	{
		i = i + 1;
	}
	new_node->name = ft_strndup(env_line, i);
	if (ft_strchr(env_line, '='))
		new_node->value = ft_strtrim(ft_strchr(env_line, '=') + 1, "\"'");
	else
		new_node->value = NULL;
	new_node->next = NULL;
	return (new_node);
}

int env_size(t_env *env)
{
	int i;

	i = 0;
	while (env)
	{
		i = i + 1;
		env = env->next;
	}
	return (i);
}

void add_env_line(t_env **env, t_env *new)
{
	t_env *temp;

	if (*env == NULL)
	{
		*env = new;
		return;
	}
	temp = *env;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void free_env_lines(t_env *env)
{
	t_env *temp;
	t_env *next;

	if (!env)
		return;
	temp = env;
	while (temp)
	{
		next = temp->next;
		free(temp->name);
		free(temp->value);
		free(temp);
		temp = next;
	}
}

void remove_line(t_env **lst, char *arg)
{
	t_env *temp;
	t_env *next_one;

	temp = *lst;
	if (temp && ft_strcmp(temp->name, arg) == 0)
	{
		*lst = temp->next;
		free(temp->name);
		free(temp->value);
		free(temp);
		return;
	}
	while (temp)
	{
		if (temp->next && ft_strcmp(temp->next->name, arg) == 0)
		{
			next_one = temp->next;
			temp->next = temp->next->next;
			free(next_one->name);
			free(next_one->value);
			free(next_one);
			return;
		}
		temp = temp->next;
	}
}
