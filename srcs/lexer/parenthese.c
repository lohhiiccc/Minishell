/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:57:36 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 03:55:27 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"

int	lex_parenthese_op(t_vector *vector, size_t *parent, size_t i)
{
	t_token_type type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = NONE;
	if (type == CHAR)
		return (1);
	parent[0]++;
	return (0);
}

int lex_parenthese_cl(t_vector *vector, size_t *parent, size_t i)
{
	t_token_type type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = NONE;
	parent[1]++;
	if (parent[0] != parent[1] || type == PARENTESE_OP \
	|| type == LOGICAL_OP || type == PIPE || type == RED_IN \
	|| type == RED_OUT)
		return (1);
	return (0);
}