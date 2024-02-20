/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:24:01 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 12:06:31 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_putnbr(int n, int *count)
{
	char		temp;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*count)++;
		n = -n;
	}
	temp = n % 10 + '0';
	if (n >= 10)
	{
		n = n / 10;
		ft_putnbr(n, count);
	}
	(*count)++;
	if (write(1, &temp, 1) == -1)
		return (-1);
	return (*count);
}
