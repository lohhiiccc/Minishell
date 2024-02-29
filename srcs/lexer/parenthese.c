/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:57:36 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 15:23:53 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "token.h"

int	lex_parenthese_op(t_vector *vector, size_t *parent, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = NONE;
	if (type == CHAR || type == PARENTESE_CL)
		return (1);
	parent[0]++;
	return (0);
}

int	lex_parenthese_cl(t_vector *vector, size_t *parent, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = NONE;
	parent[1]++;
	if ((type == CHAR || type == PARENTESE_CL))
		return (0);
	return (1);
}
