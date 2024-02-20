/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:23:10 by mjuffard          #+#    #+#             */
/*   Updated: 2023/11/29 15:46:55 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunnbr(unsigned int n, int *count)
{
	char		temp;

	temp = n % 10 + '0';
	if (n >= 10)
	{
		n = n / 10;
		ft_putunnbr(n, count);
	}
	(*count)++;
	if (write(1, &temp, 1) == -1)
		return (-1);
	return (*count);
}
