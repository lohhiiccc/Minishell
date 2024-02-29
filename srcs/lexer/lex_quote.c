/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:28:53 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 17:43:51 by lrio             ###   ########.fr       */
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
	if (last == T_PARENTESE_CL || len == 0
	|| ((t_token *)vector->addr)[i].str[len] != ((t_token *)vector->addr)[i].str[0])
		return (1);
	return (0);
}
