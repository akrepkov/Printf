/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:54:32 by akrepkov          #+#    #+#             */
/*   Updated: 2022/12/07 16:56:13 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_putstr("-2147483648");
	else if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n >= 0 && n < 10)
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putunsigned(unsigned int c, int count)
{
	if (c < 0)
	{
		c = -c;
		count++;
	}
	if (c > 9)
	{
		count += ft_putunsigned((c / 10), count);
		c = c % 10;
	}
	if (c < 10)
		count += ft_putchar(c + '0');
	return (count);
}

int	ft_put_x(unsigned int c, const char format)
{
	int	count;

	count = 0;
	if (c > 15)
	{
		count += ft_put_x((c / 16), format);
		c = c % 16;
	}
	if (c >= 0 && c < 10)
		count += ft_putchar(c + '0');
	else if (format == 'x')
		count += ft_putchar(c - 10 + 'a');
	else if (format == 'X')
		count += ft_putchar(c - 10 + 'A');
	return (count);
}
