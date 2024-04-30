/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iteri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:17:14 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/30 02:38:36 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

int	ft_vector_iteri(t_vector *vector, int (*f)(void *))
{
	size_t	i;

	i = 0;
	while (i < vector->nbr_elem)
	{
		if (f(ft_vector_get(vector, i)))
			return (1);
		i++;
	}
	return (0);
}
