/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:45:01 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/07 01:14:20 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_delete_elem(t_vector *vector, size_t n)
{
	ft_memmove(vector->addr + (n * vector->size), \
		vector->addr + ((n + 1) * vector->size), vector->nbr_elem - n);
}
