/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:46:57 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 15:27:31 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "token.h"

int	lex_string(t_vector *vector, size_t i)
{
	size_t			j;
	t_token_type	last;

	if (i > 0)
		last = ((t_token *)vector->addr)[i - 1].type;
	else
		last = NONE;
	j = 0;
	if (last == PARENTESE_CL)
		return (1);
	while (((t_token *)vector->addr)[i].str[j])
	{
		if (((t_token *)vector->addr)[i].str[j] == '&')
			return (1);
		j++;
	}
	return (0);
}
