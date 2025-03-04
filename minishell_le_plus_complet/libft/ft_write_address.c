/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:38:27 by axbaudri          #+#    #+#             */
/*   Updated: 2024/01/03 17:46:01 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_address(void *pointeur)
{
	int				count;
	unsigned long	address;

	count = 2;
	address = (unsigned long)pointeur;
	if (pointeur == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	count += ft_putnbr_base_long(address, 16);
	return (count);
}
