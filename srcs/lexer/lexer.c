/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 05:28:37 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 20:13:51 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "lexer.h"
#include "env.h"

int lexer(char *str, t_vector *tokens, t_env *env)
{
	ssize_t	syntax;

	if (!str[0] || -1 == ft_vector_init(tokens, sizeof(t_token)))
		return (-1);
	if (-1 == get_tokens(str, tokens))
		return (print_syntax_error(tokens, env, -1));
	syntax = syntax_check(tokens);
	if (-1 != syntax)
		return (print_syntax_error(tokens, env, syntax));
	tag_arg(tokens);
	return (0);
}
