/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 05:28:37 by lrio              #+#    #+#             */
/*   Updated: 2024/05/02 04:13:38 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "lexer.h"
#include "env.h"
#include "prompt.h"
#include "libft.h"

int	lexer(char *str, t_vector *tokens, t_param *param)
{
	ssize_t	syntax;
	char	*s;

	s = ft_strdup(str);
	if (s == NULL)
		return (-1);
	prompt_back_slash(s);
	if (!str || !str[0] || ft_vector_init(tokens, sizeof(t_token)) == -1)
	{
		free(s);
		return (-1);
	}
	if (get_tokens(s, tokens) == -1)
		return (print_syntax_error(tokens, param, -1, s));
	syntax = syntax_check(tokens);
	if (syntax != -1)
		return (print_syntax_error(tokens, param, syntax, s));
	tag_arg(tokens);
	free(s);
	return (0);
}
