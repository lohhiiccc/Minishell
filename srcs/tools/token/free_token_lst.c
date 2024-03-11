/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:42:54 by lrio              #+#    #+#             */
/*   Updated: 2024/03/01 05:32:41 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "token.h"

void	free_token(t_vector *vector)
{
	size_t	i;

	if (vector->nbr_elem == 0)
		return ;
	i = 0;
	while (i < vector->nbr_elem)
	{
		if ((((t_token *)vector->addr)[i].type != T_NEWLINE))
			free(((t_token *)vector->addr)[i].str);
		i++;
	}
	free(vector->addr);
}
