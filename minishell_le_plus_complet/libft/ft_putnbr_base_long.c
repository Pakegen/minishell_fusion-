/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:38:41 by axbaudri          #+#    #+#             */
/*   Updated: 2024/01/03 17:44:54 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_long(unsigned long nb, unsigned int base)
{
	int				length;
	unsigned long	i;
	const char		*tab;

	tab = "0123456789abcdef";
	length = 1;
	i = nb;
	while (i >= base)
	{
		i /= base;
		length++;
	}
	if (nb >= base)
	{
		ft_putnbr_base_long(nb / base, base);
		ft_putchar(tab[nb % base]);
	}
	else
		ft_putchar(tab[nb]);
	return (length);
}
