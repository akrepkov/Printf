/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:38:23 by akrepkov          #+#    #+#             */
/*   Updated: 2022/12/07 16:56:08 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_printptr(unsigned long tmp, const char format)
{
	int				count;

	count = 0;
	while (tmp > 15)
	{
		count += ft_printptr((tmp / 16), format);
		tmp = tmp % 16;
	}
	if (tmp >= 0 && tmp < 10)
		count += ft_putchar(tmp + '0');
	else
		count += ft_putchar(tmp - 10 + 'a');
	return (count);
}
