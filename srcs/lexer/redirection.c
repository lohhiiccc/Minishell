/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:42:20 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 02:18:10 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "token.h"

int	lex_redirect_out(t_vector *vector, size_t i)
{
	t_token_type type;

	printf("test\n");
	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = NONE;
	if (type == PIPE || type == LOGICAL_OP || type == PARENTESE_OP || \
		type == RED_OUT || type == RED_IN)
		return (1);
	return (0);

}
