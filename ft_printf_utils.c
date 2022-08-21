/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:32:56 by bammar            #+#    #+#             */
/*   Updated: 2022/08/21 21:08:51 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar_fd(int c, int fd)
{
	char	x;

	x = c;
	write(fd, &x, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != 0)
			write(fd, &s[i++], 1);
	}
	else
	{
		write(fd, "(null)", 6);
		return (6);
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		count;

	c = '0';
	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_fd("-214", 1);
		count += ft_putnbr_fd(7483648, fd);
	}
	else if (n < 0)
	{
		count += ft_putstr_fd("-", 1);
		count += ft_putnbr_fd(n * -1, fd);
	}
	else if (n < 10)
		count += ft_putchar_fd(c + n, 1);
	else
	{
		count += ft_putnbr_fd(n / 10, fd);
		count += ft_putnbr_fd(n % 10, fd);
	}
	return (count);
}
