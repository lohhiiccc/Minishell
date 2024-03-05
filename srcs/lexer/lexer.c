/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 05:28:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/05 22:32:59 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "token.h"
#include "lexer.h"

int	lexer(char *str, t_vector *tokens)
{
	if (!str[0] || -1 == ft_vector_init(tokens, sizeof(t_token)))
		return (-1);
	if (-1 == get_tokens(str, tokens))
		return (write(2, "error\n", 6), -1);
	if (1 == syntax_check(tokens))
		return (write(2, "error\n", 6));
	tag_arg(tokens);
	for (size_t j = 0; j < tokens->nbr_elem; ++j) {
		printf("type\t:%d\t| %s\n", ((t_token *)tokens->addr)[j].type, ((t_token *)tokens->addr)[j].str);
	}
	return (0);
}
