/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:49:13 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/17 23:55:51 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	size_to_malloc(long n, int len)
{
	size_t	i;

	i = 1;
	while (n >= len)
	{
		n /= len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(size_t n, char *base)
{
	char	*ret;
	int		len_base;
	size_t	i;

	len_base = ft_strlen(base);
	i = size_to_malloc(n, len_base);
	ret = malloc(i + 1);
	if (!ret)
		return (NULL);
	ret[i] = 0;
	while (--i > 0)
	{
		ret[i] = *(base + (n % len_base));
		n /= len_base;
	}
	ret[i] = *(base + (n % len_base));
	return (ret);
}
