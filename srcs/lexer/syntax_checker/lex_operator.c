/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:29:17 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 00:45:51 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "token.h"

unsigned char	lex_operator(t_vector *vector, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = T_NONE;
	if (type == T_LOGICAL_OP || type == T_RED_OUT || type == T_RED_IN
		|| type == T_PIPE || type == T_NONE || type == T_PARENTHESE_OP)
		return (1);
	return (0);
}
