/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:49:24 by lrio              #+#    #+#             */
/*   Updated: 2024/03/18 00:18:02 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void	ft_vector_free(t_vector *vector, void (*content_free)(void *))
{
	size_t	i;

	i = 0;
	if (content_free)
	{
		while (i < vector->nbr_elem)
		{
			content_free(ft_vector_get(vector, i));
			i++;
		}
	}
	free(vector->addr);
}
