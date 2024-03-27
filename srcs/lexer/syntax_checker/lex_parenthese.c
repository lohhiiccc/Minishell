/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:57:36 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 13:13:06 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdint.h>
#include "token.h"

uint8_t	lex_parenthese_op(t_vector *vector, size_t *parent, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = T_NONE;
	if (T_CMD == type
		|| T_FILES == type
		|| T_PARENTHESE_CL == type
		|| T_RED_OUT == type
		|| T_RED_IN == type)
		return (1);
	parent[0]++;
	return (0);
}

uint8_t	lex_parenthese_cl(t_vector *vector, size_t *parent, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = T_NONE;
	parent[1]++;
	if ((T_CMD == type || T_FILES == type || T_PARENTHESE_CL == type))
		return (0);
	return (1);
}
