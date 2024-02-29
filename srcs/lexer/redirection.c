/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:42:20 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 04:37:51 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "token.h"

int	lex_redirect_in(t_vector *vector, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = NONE;
	if (type == PARENTESE_OP || type == PIPE || type == RED_IN || \
		type == RED_OUT)
		return (1);
	return (0);
}

int	lex_redirect_out(t_vector *vector, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = NONE;
	if (type == PIPE || type == LOGICAL_OP || type == PARENTESE_OP || \
		type == RED_OUT || type == RED_IN)
		return (1);
	return (0);
}
