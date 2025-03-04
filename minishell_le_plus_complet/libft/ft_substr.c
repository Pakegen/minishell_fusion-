/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:14:45 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:45 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if ((size_t)ft_strlen(s) < start)
	{
		dest = (char *)malloc(sizeof(char));
		dest[0] = 0;
		return (dest);
	}
	else if ((size_t)ft_strlen(s + start) < len)
		dest = (char *)malloc((ft_strlen(s + start) + 1));
	else
		dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = 0;
	return (dest);
}
