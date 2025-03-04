/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:39:13 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:36:32 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	void			*new_var;
	unsigned char	*chaine;

	if (size && (count > SIZE_MAX / size))
		return (NULL);
	new_var = (void *)malloc(count * size);
	if (new_var == NULL)
		return (NULL);
	chaine = (unsigned char *)new_var;
	i = 0;
	while (i < count)
		chaine[i++] = '\0';
	return (new_var);
}
