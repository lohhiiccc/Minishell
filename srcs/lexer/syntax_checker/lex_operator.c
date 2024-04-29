/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:29:17 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 21:39:40 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "token.h"

uint8_t	lex_operator(t_vector *vector, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = T_NONE;
	if (type == T_LOGICAL_OP  || type == T_RED_OUT  || type == T_RED_IN
		|| type == T_PIPE  || type == T_NONE  || type == T_PARENTHESE_OP )
		return (1);
	return (0);
}
