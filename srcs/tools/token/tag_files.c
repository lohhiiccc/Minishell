/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:57:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 00:58:56 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	tag_files(t_vector *tokens)
{
	size_t	i;

	i = 0;
	while (tokens->nbr_elem > i)
	{
		if (i + 1 < tokens->nbr_elem
			&& (((t_token *)tokens->addr)[i].type == T_RED_OUT
			|| ((t_token *)tokens->addr)[i].type == T_RED_IN)
			&& ((t_token *)tokens->addr)[i + 1].type == T_CMD)
			((t_token *)tokens->addr)[i + 1].type = T_FILES;
		i++;
	}
}
