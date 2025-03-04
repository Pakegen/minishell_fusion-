/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:16:12 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:21 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		size;
	char	*new_string;

	i = 0;
	size = 0;
	new_string = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new_string == NULL)
		return (NULL);
	while (s1[i])
		new_string[size++] = s1[i++];
	i = 0;
	while (s2[i])
		new_string[size++] = s2[i++];
	new_string[size] = '\0';
	return (new_string);
}
