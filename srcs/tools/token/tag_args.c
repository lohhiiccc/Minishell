/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:31:47 by lrio              #+#    #+#             */
/*   Updated: 2024/03/06 16:27:34 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static unsigned char	is_sep(t_token_type type);

void	tag_arg(t_vector *tokens)
{
	size_t			i;
	unsigned char	have_cmd;

	i = 0;
	have_cmd = 0;
	while (i < tokens->nbr_elem)
	{
		if (is_sep(((t_token *)tokens->addr)[i].type))
			have_cmd = 0;
		if (((t_token *)tokens->addr)[i].type == T_CMD && !have_cmd)
			have_cmd = 1;
		else if (((t_token *)tokens->addr)[i].type == T_CMD && have_cmd)
			((t_token *)tokens->addr)[i].type = T_ARG;
		i++;
	}
}

static unsigned char	is_sep(t_token_type type)
{
	return (type == T_LOGICAL_OP || type == T_PIPE);
}
