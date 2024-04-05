/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:18:04 by lrio              #+#    #+#             */
/*   Updated: 2024/04/03 16:40:49 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*ft_vector_get(t_vector *vector, size_t n)
{
	if (n >= vector->nbr_elem)
		return (NULL);
	return (vector->addr + (n * vector->size));
}
