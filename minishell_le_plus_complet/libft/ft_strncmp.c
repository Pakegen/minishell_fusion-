/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:14:14 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:35 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*chaine1;
	unsigned char	*chaine2;

	chaine1 = (unsigned char *)s1;
	chaine2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (chaine1[i] && chaine1[i] == chaine2[i] && i < n - 1)
		i++;
	return (chaine1[i] - chaine2[i]);
}
