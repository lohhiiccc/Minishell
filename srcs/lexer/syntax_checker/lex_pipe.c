/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:06:57 by lrio              #+#    #+#             */
/*   Updated: 2024/03/03 22:18:53 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "token.h"

int	lex_pipe(t_vector *vector, size_t i)
{
	t_token_type	type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		type = T_NONE;
	if (type == T_CMD || type == T_FILES || type == T_PARENTHESE_CL || type == T_QUOTE)
		return (0);
	return (1);
}
