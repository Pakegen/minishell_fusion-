/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:39:14 by axbaudri          #+#    #+#             */
/*   Updated: 2023/12/05 18:39:17 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int nb)
{
	int	count;

	count = 1;
	if (nb == -2147483648)
		return (11);
	else if (nb < 0 && nb > -2147483648)
		nb = -nb;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = count_digits(n);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
			count++;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putchar('0' + n % 10);
		}
		else
			ft_putchar('0' + n);
	}
	return (count);
}

/*int main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}*/
