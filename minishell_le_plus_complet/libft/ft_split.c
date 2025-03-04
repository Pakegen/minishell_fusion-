/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:38:59 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:10 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] != c && str[0] != '\0')
	{
		count++;
		i++;
	}
	while (str[i])
	{
		if (str[i] == c && (str[i + 1] != c && str[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		size;
	char	**string_array;

	i = 0;
	size = count_strings(s, c);
	string_array = (char **)malloc(sizeof(char *) * (size + 1));
	if (string_array == NULL)
		return (NULL);
	while (i < size)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] != c && s[j] != '\0')
			j++;
		string_array[i] = ft_substr(s, 0, j);
		s += j;
		i++;
	}
	string_array[i] = 0;
	return (string_array);
}
