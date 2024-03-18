/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:38 by lrio              #+#    #+#             */
/*   Updated: 2024/03/17 16:24:36 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	sizee;

	sizee = nmemb * size;
	if (sizee != 0)
		if (sizee / size != nmemb)
			return (NULL);
	ptr = malloc(sizee);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, sizee);
	return (ptr);
}
