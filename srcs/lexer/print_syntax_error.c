/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:14:02 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 20:14:07 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "vector.h"
#include "token.h"
#include "env.h"
#include "ft_printf.h"

int8_t print_syntax_error(t_vector *tokens, t_env *env, ssize_t i, char *error)
{
	free(error);
	env->ret = 2;
	if (i < 0)
		ft_dprintf(2, "syntax error'\n");
	else if (((t_token *)tokens->addr)[i].type == T_NEWLINE)
		ft_dprintf(2, "syntax error near unexpected token `NewLine'\n");
	else if ((((t_token *)tokens->addr)[i].type == T_CMD
		|| ((t_token *)tokens->addr)[i].type == T_ARG)
		&& ((((t_token *)tokens->addr)[i].str[0] == '\'')
		|| ((t_token *)tokens->addr)[i].str[0] == '"'))
		ft_dprintf(2, "syntax error near unexpected token `%c'\n",
				   ((t_token*)tokens->addr)[i].str[0]);
	else
		ft_dprintf(2, "syntax error near unexpected token `%e'\n",
				   ((t_token*)tokens->addr)[i].str);
	free_token(tokens);
	return (-1);
}
