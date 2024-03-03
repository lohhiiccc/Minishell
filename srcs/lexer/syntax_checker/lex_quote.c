/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:28:53 by lrio              #+#    #+#             */
/*   Updated: 2024/03/03 22:23:17 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "token.h"
// a suprimer ?
unsigned char lex_quote(t_vector *vector, size_t i)
{
	t_token_type	last;

	if (i > 0)
		last = ((t_token *)vector->addr)[i - 1].type;
	else
		last = T_NONE;
	if (last == T_PARENTHESE_CL)
		return (1);
	return (0);
}
