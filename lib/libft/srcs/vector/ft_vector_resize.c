/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:08:30 by lrio              #+#    #+#             */
/*   Updated: 2024/02/28 21:09:31 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vector_resize(t_vector *vector, size_t new_size)
{
	void	*temp;

	temp = malloc(new_size * vector->size);
	if (!temp)
		return (-1);
	ft_memcpy(temp, vector->addr, vector->nbr_elem * vector->size);
	free(vector->addr);
	vector->addr = temp;
	vector->capacity = new_size;
	return (0);
}
