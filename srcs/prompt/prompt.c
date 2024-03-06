/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/03/06 17:23:53 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include "token.h"
#include <readline/readline.h>
#include <readline/history.h>

static void print_token(t_vector *tokens)
{
	for (size_t i = 0; i < tokens->nbr_elem; ++i) {
		printf("%zu: %d\t|%s\n", i , ((t_token *)tokens->addr)[i].type, ((t_token *)tokens->addr)[i].str);
	}
}

unsigned char prompt(void)
{
	char *str;
	t_vector tokens;

	tokens.nbr_elem = 0;
	str = readline("minichel>");
	if (!str)
		return (0);
	lexer(str, &tokens);//pars
	if (str && str[0])
	{
		add_history(str);
		print_token(&tokens);
	}
	free_token(&tokens);
	free(str);
	return (1);
}
