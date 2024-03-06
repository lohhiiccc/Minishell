/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:58:06 by lrio              #+#    #+#             */
/*   Updated: 2024/03/06 19:23:49 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"

static t_node get_operator(t_vector *token);

t_tree *make_operator(t_vector *tokens)
{
	return (ft_new_tree(NULL, get_operator(tokens)));
}

static t_node get_operator(t_vector *token)
{
	if (((t_token *)token->addr)[0].type == T_LOGICAL_OP)
	{
		if (((t_token *)token->addr)[0].str[0] == '&')
			return (O_AND);
		else
			return (O_OR);
	}
	else
		return (O_PIPE);
};