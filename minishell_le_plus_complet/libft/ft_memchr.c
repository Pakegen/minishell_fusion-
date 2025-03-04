/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:14:13 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:36:53 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int to_find, size_t size)
{
	size_t	i;
	char	*new_string;

	i = 0;
	new_string = (char *) str;
	while (i < size)
	{
		if (to_find > 127 || to_find < -127)
			to_find %= 128;
		if (new_string[i] == (char)to_find)
			return (new_string + i);
		else
			i++;
	}
	return (0);
}
