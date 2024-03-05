/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_parenthese.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:00:21 by lrio              #+#    #+#             */
/*   Updated: 2024/03/02 02:43:27 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static void	fill_index_range(t_vector *tokens, size_t *index_r);

//todo: securiser vector add
int next_parent(t_vector *tokens, t_vector *vector)
{
	size_t		index_r[2];
	(void)vector;
	fill_index_range(tokens, index_r);

	return (0);
}

/*
 * return index range of next parenthese indent
 */

static void	fill_index_range(t_vector *tokens, size_t *index_r)
{
	size_t	indent;

	indent = 0;
	ft_bzero(index_r, sizeof(size_t) * 2);
	while (tokens->nbr_elem > index_r[0]
		&& ((t_token *)tokens->addr)[index_r[0]].type != T_PARENTHESE_OP)
		index_r[0]++;
	while (tokens->nbr_elem > index_r[1])
	{
		if (((t_token *)tokens->addr)[index_r[1]].type == T_PARENTHESE_OP)
			indent++;
		else if (((t_token *)tokens->addr)[index_r[1]].type == T_PARENTHESE_CL)
		{
			indent--;
			if (indent == 0)
				break ;
		}
		index_r[1]++;
	}
}
