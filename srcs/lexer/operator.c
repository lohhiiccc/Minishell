/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:29:17 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 01:51:53 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "token.h"

int	lex_operator(t_vector *vector, size_t i)
{
	t_token_type type;

	if (i > 0)
		type = ((t_token *)vector->addr)[i - 1].type;
	else
		return (0);
	if (type == LOGICAL_OP || type == RED_OUT || type == RED_IN || type == PIPE)
		return (1);
	return (0);

}