/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:42:20 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 00:46:39 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "token.h"
#include <stdint.h>
//<< and <
uint8_t	lex_redirect_in(t_vector *vector, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = T_NONE;
	if (type == T_RED_IN || type == T_RED_OUT)
		return (1);
	return (0);
}
//> and >>

uint8_t	lex_redirect_out(t_vector *vector, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = T_NONE;
	if (type == T_RED_IN || type == T_RED_OUT)
		return (1);
	return (0);
}
