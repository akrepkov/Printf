/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:42:29 by akrepkov          #+#    #+#             */
/*   Updated: 2022/12/07 15:17:46 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_printptr(unsigned long c, const char format);
int	ft_putnbr(int n);
int	ft_printf(const char *str, ...);
int	ft_putunsigned(unsigned int c, int count);
int	ft_put_x(unsigned int c, const char format);

#endif