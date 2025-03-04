/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:28:20 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 04:28:22 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_redirection_flags_mode(const char *op, int *flags, int *mode)
{
	int	cmp;

	cmp = ft_strcmp(op, ">");
	if (cmp == 0)
	{
		*flags = O_WRONLY | O_CREAT | O_TRUNC;
		*mode = 0644;
		return (1);
	}
	cmp = ft_strcmp(op, ">>");
	if (cmp == 0)
	{
		*flags = O_WRONLY | O_CREAT | O_APPEND;
		*mode = 0644;
		return (1);
	}
	cmp = ft_strcmp(op, "<");
	if (cmp == 0)
	{
		*flags = O_RDONLY;
		*mode = 0;
		return (1);
	}
	return (0);
}

int	adv_handle_redirect(const char *target, const char *op, int std_fd)
{
	int	flags;
	int	mode;
	int	ret;
	int	fd;

	if (get_redirection_flags_mode(op, &flags, &mode))
	{
		ret = redirect_file(target, std_fd, flags, mode);
		return (ret);
	}
	if (ft_strcmp(op, ">&") == 0)
	{
		fd = ft_atoi(target);
		if (dup2(fd, std_fd) == -1)
		{
			perror("dup2");
			return (-1);
		}
		return (0);
	}
	return (-1);
}

int	handle_redirection_char(const char *file, const char *op)
{
	int	std_fd;

	if (ft_strcmp(op, "<") == 0)
	{
		std_fd = STDIN_FILENO;
	}
	else
	{
		std_fd = STDOUT_FILENO;
	}
	return (adv_handle_redirect(file, op, std_fd));
}
