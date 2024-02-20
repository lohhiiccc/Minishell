/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:16:39 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 12:48:06 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!n)
		return (NULL);
	i = 0;
	while (((unsigned char *)s)[i] != ((unsigned char)c) && i < n - 1)
		i++;
	if (((unsigned char *)s)[i] == ((unsigned char)c))
		return ((&((unsigned char *)s)[i]));
	else
		return (0);
}
