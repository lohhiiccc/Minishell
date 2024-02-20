/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:57:06 by lrio              #+#    #+#             */
/*   Updated: 2023/11/18 00:31:29 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convbase(long int num, int base, char *str, t_utils u)
{
	char	b;

	b = 0;
	if (!num)
		return (-1);
	else
	{
		b = num % base;
		convbase(num / base, base, str, u);
	}
	if (-1 == fp_putchar(*(str + b), u))
		return (-1);
	return (0);
}

int	fp_putnbr_base(unsigned int nbr, char *base, t_utils u)
{
	unsigned long	nb2;

	nb2 = nbr;
	if (nbr == 0)
	{
		if (-1 == fp_putchar(base[0], u))
			return (-1);
		return (0);
	}
	if (-1 == convbase(nb2, fp_strlen(base), base, u))
		return (-1);
	return (1);
}
