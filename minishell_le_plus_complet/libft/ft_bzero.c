/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:38:13 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:36:28 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t n)
{
	size_t			i;
	unsigned char	*chaine;

	chaine = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		*chaine++ = '\0';
		i++;
	}
}
