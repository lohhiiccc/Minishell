/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:05:16 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 12:19:04 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vector_add(t_vector *vector, void *elem)
{
	if (vector->capacity == vector->nbr_elem)
	{
		if (ft_vector_resize(vector, vector->capacity * 2) == -1)
		{
			free(vector->addr);
			return (-1);
		}
	}
	ft_memcpy(vector->addr + vector->nbr_elem * vector->size, elem, \
		vector->size);
	vector->nbr_elem++;
	return (1);
}
