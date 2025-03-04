/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:42:22 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:43 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] != c)
			i++;
		else
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		end;
	char	*trimmed_str;

	i = 0;
	j = 0;
	end = ft_strlen(s1);
	if (s1 == NULL)
		return (0);
	while (is_in_set(s1[i], set) == 1)
		i++;
	while (is_in_set(s1[end - 1], set) == 1 && end > i)
		end--;
	trimmed_str = (char *)malloc(sizeof(char) * (end - i + 1));
	if (trimmed_str == NULL)
		return (NULL);
	while (i < end)
		trimmed_str[j++] = s1[i++];
	trimmed_str[j] = '\0';
	return (trimmed_str);
}
