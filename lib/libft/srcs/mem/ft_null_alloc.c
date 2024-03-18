/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:06:49 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 01:07:01 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_null_alloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_len;

	total_len = nmemb * size;
	if (total_len != 0 && total_len / size != nmemb)
		return (NULL);
	ptr = malloc(total_len);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr + total_len - size, size);
	return (ptr);
}
