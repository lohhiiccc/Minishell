/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:49:24 by lrio              #+#    #+#             */
/*   Updated: 2024/03/05 23:49:28 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_vector_free(t_vector *vector, void (* content_free)(void *))
{
	size_t	i;

	i = 0;
	while (i < vector->nbr_elem)
	{
		content_free(ft_vector_get(vector, i));
		i++;
	}
	free(vector->addr);
}
