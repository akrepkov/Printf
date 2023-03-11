/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:48:56 by akrepkov          #+#    #+#             */
/*   Updated: 2022/12/16 16:22:03 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	res;

	res = 0;
	if (format == 'c')
		res += ft_putchar(va_arg(args, int));
	else if (format == 's')
		res += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
	{
		res += ft_putstr ("0x");
		res += ft_printptr((va_arg(args, unsigned long)), format);
	}
	else if (format == 'd' || format == 'i')
		res += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		res += ft_putunsigned((va_arg(args, unsigned int)), res);
	else if (format == 'x' || format == 'X')
		res += ft_put_x((va_arg(args, unsigned int)), format);
	else if (format == '%')
		res += ft_putchar('%');
	else if (format != ' ')
		res += write(1, &format, 1);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	args;

	i = 0;
	res = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
			{
				res += ft_format(args, str[i + 1]);
				i++;
			}
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (res);
}
