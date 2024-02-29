/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 00:45:22 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"
#include "lexer.h"

void prompt(void)
{
	char *str;

	while (1)
	{
		str = readline("minichel>");
		if (ft_strncmp("exit", str, -1) == 0)
		{
			free(str);
			break;
		}
		if (str)
			add_history(str);
		if (lexer(str))
			write(2, "syntax error\n", 14);
		free(str);
	}
	rl_clear_history();
}
