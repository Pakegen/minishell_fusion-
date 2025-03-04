/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:40:34 by axbaudri          #+#    #+#             */
/*   Updated: 2023/11/20 15:40:36 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n <= -10 && n > -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
	else if (n < 0 && n > -10)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putchar_fd('0' + n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

/*int	main(void)
{
	int nb = -2147483647;
	int fd = open("test.txt", O_WRONLY);
	ft_putnbr_fd(nb, fd);
	return (0);
}*/
