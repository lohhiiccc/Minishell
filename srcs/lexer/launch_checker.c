/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:37:08 by lrio              #+#    #+#             */
/*   Updated: 2024/03/18 01:06:33 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "lexer.h"
#include "libft.h"

static uint8_t	lex_last(const size_t *parent, t_token_type type);
static uint8_t	lex_global(t_vector *vector, size_t i, size_t *parent,
							t_token_type type);

uint8_t	syntax_check(t_vector *tokens)
{
	size_t			i;
	t_token_type	type;
	size_t			parent[2];

	i = 0;
	ft_memset(parent, 0, sizeof(size_t) * 2);
	while (i < tokens->nbr_elem - 1)
	{
		type = ((t_token *)tokens->addr)[i].type;
		if (lex_global(tokens, i, parent, type))
			return (1);
		i++;
	}
	type = ((t_token *)tokens->addr)[tokens->nbr_elem - 2].type;
	if (lex_last(parent, type))
		return (1);
	return (0);
}

static uint8_t	lex_global(t_vector *vector, size_t i, size_t *parent, \
									t_token_type type)
{
	return ((type == T_PARENTHESE_OP && lex_parenthese_op(vector, parent, i))
		|| (type == T_PARENTHESE_CL && lex_parenthese_cl(vector, parent, i))
		|| (type == T_LOGICAL_OP && lex_operator(vector, i))
		|| (type == T_RED_OUT && lex_redirect_out(vector, i))
		|| (type == T_RED_IN && lex_redirect_in(vector, i))
		|| (type == T_PIPE && lex_pipe(vector, i))
		|| (type == T_CMD && lex_string(vector, i)));
}

static uint8_t	lex_last(const size_t *parent, t_token_type type)
{
	return (parent[0] != parent[1]
		|| !(type == T_CMD
			|| type == T_FILES
			|| type == T_PARENTHESE_CL
			|| type == T_IS_SPACE
			|| type == T_NONE));
}
