/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:06:57 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 21:54:45 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "token.h"

uint8_t	lex_pipe(t_vector *vector, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = T_NONE;
	if (T_CMD == type || T_FILES == type || T_PARENTHESE_CL == type)
		return (0);
	return (1);
}
