/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:37:52 by lrio              #+#    #+#             */
/*   Updated: 2024/01/14 15:23:54 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <errno.h>

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\f' || str[i] == ' ' \
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			i++;
		else
			return (i);
	}
	return (i);
}

long	ft_atol(const char *str)
{
	int		start;
	long	i;
	long	return_value;
	int		is_neg;

	is_neg = 0;
	i = 0;
	return_value = 0;
	start = ft_isspace(str);
	if (str[start] == '+' || str[start] == '-')
		if (str[start++] == '-')
			is_neg = 1;
	while (str[start + i] && fp_isdigit(str[start + i]))
		return_value = (return_value * 10) + (str[start + i++] - '0');
	if (return_value < 0)
	{
		errno = ERANGE;
		return (-1);
	}
	if (str[start + i] && !fp_isdigit(str[start + i]))
		errno = ERANGE;
	if (is_neg == 1)
		return_value = -return_value;
	return (return_value);
}

int	ft_atoi(const char *str)
{
	long	tmp;

	if (!str)
		return (0);
	tmp = ft_atol(str);
	if (!(tmp >= INT_MIN && tmp <= INT_MAX))
		errno = ERANGE;
	return (ft_atol(str));
}
