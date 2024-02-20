/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:13:42 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 12:05:47 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_check(char const c, char const *sep)
{
	size_t	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	putarg(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'u')
		return (ft_putunnbr(va_arg(arg, unsigned int), &count));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, unsigned int), &count));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 'p')
		return (ft_putaddr(va_arg(arg, size_t), LOWER_HEX, &count));
	else if (c == 'x')
		return (ft_putnbrbase(va_arg(arg, unsigned int), LOWER_HEX, &count));
	else if (c == 'X')
		return (ft_putnbrbase(va_arg(arg, unsigned int), UPPER_HEX, &count));
	else
		return (ft_putchar('%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		ret;
	int		temp;

	if (!str)
		return (-1);
	ret = 0;
	i = -1;
	va_start(arg, str);
	while (str[++i])
	{
		temp = ret;
		if (str[i] == '%' && ft_check(str[i + 1], "udiscpxX%"))
			ret = putarg(arg, str[++i]) + ret;
		else
			ret = ft_putchar(str[i]) + ret;
		if (temp > ret)
		{
			va_end(arg);
			return (-1);
		}
	}
	va_end(arg);
	return (ret);
}
