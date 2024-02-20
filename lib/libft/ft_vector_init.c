/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:56:22 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/01 01:04:58 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	vector_init(t_vector *vector, size_t size)
{
	vector->addr = malloc(8 * size);
	if (!vector->addr)
		return (-1);
	vector->size = size;
	vector->nbr_elem = 0;
	vector->capacity = 8;
	return (0);
}
