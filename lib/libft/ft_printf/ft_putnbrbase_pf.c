/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:38:10 by mjuffard          #+#    #+#             */
/*   Updated: 2023/11/29 15:48:16 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbrbase(unsigned int n, char *base, int *count)
{
	char		temp;

	if (!check_base(base))
		return (-1);
	temp = n % ft_strlen(base);
	if (n >= (unsigned int)ft_strlen(base))
	{
		n = n / ft_strlen(base);
		ft_putnbrbase(n, base, count);
	}
	if (write(1, base + temp, 1) == -1)
		return (-1);
	(*count)++;
	return (*count);
}
