/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:14:33 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:04 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int value, size_t n)
{
	size_t	i;
	char	*chaine;

	i = 0;
	chaine = src;
	while (i < n)
	{
		chaine[i] = (char) value;
		i++;
	}
	return ((char *) chaine);
}
