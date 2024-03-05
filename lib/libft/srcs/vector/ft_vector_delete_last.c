/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete_last.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:45:01 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/04 22:37:48 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_delete_last(t_vector *vector)
{
	free(vector->addr + ((vector->nbr_elem - 1) * vector->size));
	vector->nbr_elem--;
}
