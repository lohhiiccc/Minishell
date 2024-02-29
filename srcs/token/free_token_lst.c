/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:42:54 by lrio              #+#    #+#             */
/*   Updated: 2024/02/28 23:52:48 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "token.h"

void	free_token(t_vector *vector)
{
	size_t	i;

	i = 0;
	while (i < vector->nbr_elem)
	{
		free(((t_token *)vector->addr)[i].str);
		i++;
	}
	free(vector->addr);
}
