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

int	lexer(char *str, t_vector *tokens)
{
	if (!str[0] || -1 == ft_vector_init(tokens, sizeof(t_token)))
		return (-1);
	if (-1 == get_tokens(str, tokens))
		return (print_syntax_error(tokens));
	if (0 != syntax_check(tokens))
		return (print_syntax_error(tokens));
	tag_arg(tokens);
	return (0);
}
