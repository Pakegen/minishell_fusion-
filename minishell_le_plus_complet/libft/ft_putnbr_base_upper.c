/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:44:32 by axbaudri          #+#    #+#             */
/*   Updated: 2024/01/03 17:44:37 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_upper(unsigned int nb, unsigned int base)
{
	int				length;
	unsigned int	i;
	const char		*tab;

	tab = "0123456789ABCDEF";
	length = 1;
	i = nb;
	while (i >= base)
	{
		i /= base;
		length++;
	}
	if (nb >= base)
	{
		ft_putnbr_base_upper(nb / base, base);
		ft_putchar(tab[nb % base]);
	}
	else
		ft_putchar(tab[nb]);
	return (length);
}
