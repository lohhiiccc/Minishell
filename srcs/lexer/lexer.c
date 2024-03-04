/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 05:28:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 00:48:04 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}
