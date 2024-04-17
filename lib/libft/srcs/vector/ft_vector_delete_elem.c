/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:45:01 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/17 16:30:58 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include "ft_printf.h"
void	ft_vector_delete_elem(t_vector *vector, size_t n)
{
	ft_memmove(vector->addr + (n * vector->size), \
		vector->addr + ((n + 1) * vector->size), (vector->nbr_elem - n) * vector->size);
	vector->nbr_elem--;
}
