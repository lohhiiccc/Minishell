/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 05:28:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/02 05:42:34 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "token.h"
#include "lexer.h"

static unsigned char	lex_last(const size_t *parent, t_token_type type);
static unsigned char	lex_global(t_vector *vector, size_t i, size_t *parent,
							t_token_type type);

int lexer(char *str, t_vector *tokens)
{
	size_t			i;
	size_t			parent[2];
	t_token_type	type;

	if (!str[0] || -1 == ft_vector_init(tokens, sizeof(t_token)))
		return (0);
	if (-1 == get_tokens(str, tokens))
		return (0);
	i = 0;
	ft_memset(parent, 0, sizeof(size_t) * 2);
	while (i < tokens->nbr_elem)
	{
		type = ((t_token *)tokens->addr)[i].type;
		if (lex_global(tokens, i, parent, type))
			return (1);
		i++;
	}
	type = ((t_token *)tokens->addr)[tokens->nbr_elem - 1].type;
	if (lex_last(parent, type))
		return (1);
	return (0);
}

static unsigned char	lex_global(t_vector *vector, size_t i, size_t *parent, \
									t_token_type type)
{
	return ((type == T_PARENTHESE_OP && lex_parenthese_op(vector, parent, i))
		|| (type == T_PARENTHESE_CL && lex_parenthese_cl(vector, parent, i))
		|| (type == T_LOGICAL_OP && lex_operator(vector, i))
		|| (type == T_RED_OUT && lex_redirect_out(vector, i))
		|| (type == T_RED_IN && lex_redirect_in(vector, i))
		|| (type == T_PIPE && lex_pipe(vector, i))
		|| (type == T_CHAR && lex_string(vector, i))
		|| (type == T_QUOTE && lex_quote(vector, i)));
}

static	unsigned char	lex_last(const size_t *parent, t_token_type type)
{
	return (parent[0] != parent[1] || !(type == T_CHAR
			|| type == T_QUOTE || type == T_PARENTHESE_CL
			|| type == T_IS_SPACE || type == T_NONE));
}
