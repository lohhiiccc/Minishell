/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iteri_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:10:26 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/30 02:38:05 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "vector.h"

int	ft_vector_iteri_fd(t_vector *vector, int (*f)(void *, int), int fd)
{
	size_t	i;

	i = 0;
	while (i < vector->nbr_elem)
	{
		if (f(ft_vector_get(vector, i), fd))
			return (1);
		i++;
	}
	return (0);
}
