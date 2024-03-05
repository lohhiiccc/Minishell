/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/03/05 18:49:31 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include "token.h"
#include <readline/readline.h>
#include <readline/history.h>

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
		add_history(str);
	free_token(&tokens);
	free(str);
	return (1);
}
