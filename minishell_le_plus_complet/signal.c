/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:46:34 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 03:46:35 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n\033[0;32mminishell> \033[0m", 23);
}

void handle_sigquit(int sig)
{
	(void)sig;
	write(1, "\b\b \b\b", 6);
}

void setup_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
