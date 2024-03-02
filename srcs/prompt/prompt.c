/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/03/02 02:36:23 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "minishell.h"
#include "token.h"
#include "lexer.h"
#include "parsing.h"

void prompt(void)
{
	char *str;
	t_vector tokens;

	tokens.nbr_elem = 0;
	while (1)
	{
		str = readline("minichel>");
		if (NULL == str || ft_strncmp("exit", str, -1) == 0)
		{
			rl_clear_history();
			free(str);
			break;
		}
		if (str)
			add_history(str);
		if (lexer(str, &tokens))
		{
			free(str);
			free_token(&tokens);
			write(2, "syntax error\n", 14);
			continue ;
		}
		next_parent(&tokens);
		free(str);
		free_token(&tokens);
	}
	rl_clear_history();
}
