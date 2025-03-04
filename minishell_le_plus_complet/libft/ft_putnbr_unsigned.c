/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:44:42 by axbaudri          #+#    #+#             */
/*   Updated: 2024/01/03 17:44:45 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int nb)
{
	int	count;

	count = 1;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = count_digits(n);
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putchar('0' + n % 10);
	}
	else
		ft_putchar('0' + n);
	return (count);
}
