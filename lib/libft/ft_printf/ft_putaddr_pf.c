/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:26:55 by mjuffard          #+#    #+#             */
/*   Updated: 2023/11/30 12:12:22 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(size_t n, char *base, int *count)
{
	char		temp;

	if (!n)
		return (ft_putstr("(nil)"));
	if (*count == 0)
		if (ft_putstr("0x") == -1)
			return (-1);
	(*count)++;
	temp = n % ft_strlen(base);
	if (n >= ft_strlen(base))
	{
		n = n / ft_strlen(base);
		ft_putaddr(n, base, count);
	}
	if (write(1, base + temp, 1) == -1)
		return (-1);
	return (*count + 2);
}
