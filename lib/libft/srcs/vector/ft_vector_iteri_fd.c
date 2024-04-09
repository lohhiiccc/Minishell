/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iteri_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:10:26 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/07 21:11:51 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

int	ft_vector_iteri_fd(t_vector *vector, void (*f)(void *, int), int fd)
{
	size_t	i;

	i = 0;
	while (i < vector->nbr_elem)
	{
		f(ft_vector_get(vector, i), fd);
		i++;
	}
//	printf("\n");
	return (0);
}
