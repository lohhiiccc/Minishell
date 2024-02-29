/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 02:20:27 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"
#include "lexer.h"

//todo: si type == CHAR verifier quil ny a pas de &
int	lexer(char *str)
{
	t_vector	vector;
	size_t 		i;
	size_t 		parent[2];

	if (-1 == vector_init(&vector, sizeof(t_token)))
		return (0);
	if (-1 == get_tokens(str, &vector))
		return (0);
	i = 0;
	ft_memset(parent, 0, sizeof(size_t) * 2);
	while (i < vector.nbr_elem)
	{
		if ((((t_token *)vector.addr)[i].type == PARENTESE_OP && lex_parenthese_op(&vector, parent, i)) || \
			(((t_token *)vector.addr)[i].type == PARENTESE_CL && lex_parenthese_cl(&vector, parent, i)) || \
			(((t_token *)vector.addr)[i].type == LOGICAL_OP && lex_operator(&vector, i)) || \
			(((t_token *)vector.addr)[i].type == RED_OUT && lex_redirect_out(&vector, i)))
			return (free_token(&vector), 1);

		i++;
	}
	if (parent[0] != parent[1])
		return (free_token(&vector), 1);

	free_token(&vector);
	return (0);
}
