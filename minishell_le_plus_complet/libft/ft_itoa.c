/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:16:08 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:38:06 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int nb)
{
	int	count;

	count = 1;
	if (nb == -2147483648)
		return (11);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			count++;
		}
		while (nb >= 10)
		{
			nb /= 10;
			count++;
		}
		return (count);
	}
	return (0);
}

static void	change_number(int i, long n, char *number)
{
	if (n == 0)
		number[0] = '0';
	else
	{
		while (n != 0)
		{
			number[i] = ('0' + n % 10);
			n /= 10;
			i--;
		}
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	int		size;
	char	*number;

	nb = (long)n;
	size = count_digits(n);
	i = size - 1;
	number = (char *)malloc(sizeof(char) * (size + 1));
	if (number == NULL)
		return (NULL);
	if (nb < 0)
	{
		number[0] = '-';
		nb = -nb;
	}
	change_number(i, nb, number);
	number[size] = '\0';
	return (number);
}
