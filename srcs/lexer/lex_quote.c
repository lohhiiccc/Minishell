/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:28:53 by lrio              #+#    #+#             */
/*   Updated: 2024/03/02 05:41:03 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "token.h"

int	lex_quote(t_vector *vector, size_t i)
{
	t_token_type	last;
	size_t 			len;

	len = ft_strlen(((t_token *)vector->addr)[i].str) - 1;
	if (i > 0)
		last = ((t_token *)vector->addr)[i - 1].type;
	else
		last = T_NONE;
	if (last == T_PARENTHESE_CL || len == 0)
		return (1);
	return (0);
}
