/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:56:03 by lrio              #+#    #+#             */
/*   Updated: 2024/01/21 17:45:25 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_format(char c, va_list info, t_utils u)
{
	if (c == 'p')
		return (fp_printaddress(va_arg(info, unsigned long long), u));
	if (c == 'c')
		return (fp_putchar(va_arg(info, int), u));
	if (c == 's')
		return (fp_putstr(va_arg(info, char *), u));
	if (c == '%')
		return (fp_putchar('%', u));
	if (c == 'd' || c == 'i')
		return (fp_putnbr(va_arg(info, int), u));
	if (c == 'X')
		return (fp_putnbr_base((unsigned int) va_arg(info, int), \
		"0123456789ABCDEF", u));
	if (c == 'x')
		return (fp_putnbr_base((unsigned int) va_arg(info, int), \
		"0123456789abcdef", u));
	if (c == 'u')
		return (fp_putnbr_base(va_arg(info, unsigned int), \
		"0123456789", u));
	return (1);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list	info;
	int		i;
	int		len;
	t_utils	u;

	u.fd = fd;
	len = 0;
	u.len = &len;
	i = 0;
	va_start(info, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (-1 == ft_format(s[i], info, u))
				return (va_end(info), -1);
		}
		else
			if (-1 == fp_putchar(s[i], u))
				return (va_end(info), -1);
		i++;
	}
	va_end(info);
	return (*(u.len));
}
