/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:56:23 by lrio              #+#    #+#             */
/*   Updated: 2024/01/18 00:09:36 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dec2hex(unsigned long long num, t_utils u)
{
	char	hex;

	hex = 0;
	if (!num)
		return (1);
	else
	{
		hex = num % 16;
		dec2hex(num / 16, u);
	}
	if (hex > 9)
	{
		if (!fp_putchar('a' + (hex - 10), u))
			return (-1);
	}
	else
	{
		if (!fp_putchar(hex + '0', u))
			return (-1);
	}
	return (1);
}

int	fp_printaddress(unsigned long long address, t_utils u)
{
	if (!address)
		return (fp_putstr("(nil)", u));
	if (-1 == fp_putstr("0x", u))
		return (-1);
	if (-1 == dec2hex(address, u))
		return (-1);
	return (1);
}
