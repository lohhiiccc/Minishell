/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:23:31 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 12:12:26 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	size_to_malloc(int n)
{
	int	ret;
	int	temp;

	temp = n;
	ret = 1;
	if (temp < 0)
		ret++;
	while (temp / 10)
	{
		temp = temp / 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		neg;

	neg = 0;
	ret = ft_calloc(size_to_malloc(n) + 1, sizeof(char));
	if (!ret)
		return (0);
	if (n == INT_MIN)
	{
		ret[size_to_malloc(n) - 1] = '8';
		n = n / 10;
	}
	if (n < 0)
	{
		n = -n;
		neg++;
		ret[0] = '-';
	}
	while (size_to_malloc(n) != 1)
	{
		ret[size_to_malloc(n) + neg - 1] = n % 10 + '0';
		n = n / 10;
	}
	ret[size_to_malloc(n) + neg - 1] = n % 10 + '0';
	return (ret);
}
