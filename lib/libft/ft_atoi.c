/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:35:03 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 12:11:46 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int			sign;
	long int	ret;
	size_t		i;

	i = 0;
	ret = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		ret = ret * 10 + (nptr[i] - '0');
		if (ret < 0 && sign == -1)
			return ((int)LONG_MIN);
		if (ret < 0 && sign == 1)
			return ((int)LONG_MAX);
		i++;
	}
	return (ret * sign);
}
