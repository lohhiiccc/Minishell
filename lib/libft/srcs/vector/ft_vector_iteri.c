/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iteri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:17:14 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/15 01:19:16 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_vector_iteri(t_vector *vector, void (*f)(void *))
{
	size_t	i;

	i = 0;
	while (i < vector->nbr_elem)
	{
		f(ft_vector_get(vector, i));
		i++;
	}
	printf("\n");
	return (0);
}
