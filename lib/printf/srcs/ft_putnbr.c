/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:56:59 by lrio              #+#    #+#             */
/*   Updated: 2024/01/18 00:12:39 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fp_putnbr(int n, t_utils u)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		if (-1 == fp_putchar('-', u))
			return (-1);
		num = -num;
	}
	if (num < 10)
	{
		if (-1 == fp_putchar(num + '0', u))
			return (-1);
		return (1);
	}
	else
	{
		if (-1 == fp_putnbr(num / 10, u))
			return (-1);
		if (-1 == fp_putchar('0' + (num % 10), u))
			return (-1);
	}
	return (1);
}
