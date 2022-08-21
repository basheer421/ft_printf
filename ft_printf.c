/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:56:33 by bammar            #+#    #+#             */
/*   Updated: 2022/08/21 04:43:06 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hexa(long long n, int small)
{
	long long	x;
	char		final[100];
	int			rem;
	int			i;
	int			j;

	x = n;
	i = 0;
	while (x != 0)
	{
		rem = x % 16;
		if (rem < 10)
			final[i++] = rem + '0';
		else
			final[i++] = (rem + '0' + 7) + (small * ('a' - 'A'));
		x = x / 16;
	}
	final[i] = 0;
	j = (int)ft_strlen(final);
	while (j >= 1)
		ft_putchar_fd(final[--j], 1);
}

static void	print_pointer(unsigned long p)
{
	ft_putstr_fd("0x", 1);
	print_hexa((long)(long)p, 1);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	c;

	c = '0';
	if (n < 10)
	{
		c += n;
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
}

static void	print_case(const char *format, va_list ap, int i)
{
	if (format[i + 1] == '%')
		ft_putchar_fd('%', 1);
	else if (format[i + 1] == 's')
		ft_putstr_fd((char *)va_arg(ap, char *), 1);
	else if (format[i + 1] == 'c')
		ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		ft_putnbr_fd((int)va_arg(ap, int), 1);
	else if (format[i + 1] == 'u')
		ft_putunbr_fd(va_arg(ap, int), 1);
	else if (format[i + 1] == 'p')
		print_pointer(va_arg(ap, unsigned long));
	else if (format[i + 1] == 'x')
		print_hexa(va_arg(ap, long long), 1);
	else if (format[i + 1] == 'X')
		print_hexa(va_arg(ap, long long), 0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			print_case(format, ap, i);
			i += 2;
		}
		if (format[i] != 0 && format[i] != '%')
			ft_putchar_fd(format[i], 1);
		if (format[i] != '%')
			i++;
	}
	va_end(ap);
	return (0);
}

// int	main(void)
// {
// 	// char *x = "";
// 	// char *y = malloc(0);
// 	ft_printf("%u\n", -1);
// 	printf("%u\n", -1);
// 	// free(y);
// 	return (0);
// }