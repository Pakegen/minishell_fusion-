/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:14:38 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:36 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && n == 0)
		return (0);
	if (ft_strlen(to_find) == 0)
		return ((char *) str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < n)
		{
			j++;
			if (j == (size_t)ft_strlen(to_find) && n >= i + j)
				return ((char *) str + i);
		}
		i++;
	}
	return (NULL);
}
