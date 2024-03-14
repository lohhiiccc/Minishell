/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:36:15 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/12 17:03:31 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vector_add_ptr(t_vector *vector, void *elem)
{
	if (vector->capacity == vector->nbr_elem)
	{
		if (ft_vector_resize(vector, vector->capacity * 2) == -1)
		{
			free(vector->addr);
			return (-1);
		}
	}
	*(void **)(vector->addr + vector->nbr_elem * vector->size) = elem;
	vector->nbr_elem++;
	return (1);
}