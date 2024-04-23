/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:41:09 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 17:42:31 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

int	ft_vector_insert(t_vector *vector, void *elem, size_t index, size_t n)
{
	while (vector->capacity < vector->nbr_elem + n)
		if (vector->capacity == vector->nbr_elem
			&& ft_vector_resize(vector, vector->capacity * 2) == -1)
			return (-1);
	ft_memmove(vector->addr + ((index + n) * vector->size), vector->addr
		+ (index * vector->size), ((vector->nbr_elem - index) * vector->size));
	ft_memcpy(vector->addr + index, elem, vector->size);
	vector->nbr_elem++;
	return (0);
}
