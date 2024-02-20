/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:14:38 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 12:14:44 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vector_resize(t_vector *vector, size_t new_size)
{
	void	*temp;

	temp = malloc(new_size * vector->size);
	if (!temp)
		return (-1);
	ft_memcpy(temp, vector->addr, vector->nbr_elem);
	free(vector->addr);
	vector->addr = temp;
	vector->capacity = new_size;
	return (0);
}
