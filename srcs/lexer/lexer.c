/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 04:45:42 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"
#include "lexer.h"

static unsigned char	lex_last(const size_t *parent, t_token_type type);
static unsigned char	lex_global(t_vector *vector, size_t i, size_t *parent,
							t_token_type type);

int	lexer(char *str)
{
	t_vector		vector;
	size_t			i;
	size_t			parent[2];
	t_token_type	type;

	if (!str[0] || -1 == vector_init(&vector, sizeof(t_token)))
		return (0);
	if (-1 == get_tokens(str, &vector))
		return (0);
	i = 0;
	ft_memset(parent, 0, sizeof(size_t) * 2);
	while (i < vector.nbr_elem)
	{
		type = ((t_token *)vector.addr)[i].type;
		if (lex_global(&vector, i, parent, type))
			return (free_token(&vector), 1);
		i++;
	}
	type = ((t_token *)vector.addr)[vector.nbr_elem - 1].type;
	if (lex_last(parent, type))
		return (free_token(&vector), 1);
	free_token(&vector);
	return (0);
}

static unsigned char	lex_global(t_vector *vector, size_t i, size_t *parent, \
									t_token_type type)
{
	return ((type == T_PARENTESE_OP && lex_parenthese_op(vector, parent, i))
		|| (type == T_PARENTESE_CL && lex_parenthese_cl(vector, parent, i))
		|| (type == T_LOGICAL_OP && lex_operator(vector, i))
		|| (type == T_RED_OUT && lex_redirect_out(vector, i))
		|| (type == T_RED_IN && lex_redirect_in(vector, i))
		|| (type == T_PIPE && lex_pipe(vector, i))
		|| (type == T_CHAR && lex_string(vector, i)));
}

static	unsigned char	lex_last(const size_t *parent, t_token_type type)
{
	return (parent[0] != parent[1] || !(type == T_CHAR
										|| type == T_QUOTE || type == T_PARENTESE_CL
										|| type == T_IS_SPACE || type == T_NONE));
}
