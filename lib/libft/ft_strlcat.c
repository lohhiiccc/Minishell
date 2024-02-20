/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:24:52 by mjuffard          #+#    #+#             */
/*   Updated: 2023/11/13 13:40:56 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;

	if (!dst && !size)
		return (0);
	lendst = 0;
	i = 0;
	while (dst[lendst] && lendst < size)
		lendst++;
	if (lendst != size)
	{
		while (lendst + i < size - 1 && src[i])
		{
			dst[lendst + i] = src[i];
			i++;
		}
		dst[lendst + i] = 0;
	}
	return (ft_strlen(src) + lendst);
}
