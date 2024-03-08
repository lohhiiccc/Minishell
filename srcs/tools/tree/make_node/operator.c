/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:58:06 by lrio              #+#    #+#             */
/*   Updated: 2024/03/07 22:25:29 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"

static t_node get_operator(t_token *token);

t_tree *make_operator(t_token *tokens)
{
	return (ft_new_tree(NULL, get_operator(tokens)));
}

static t_node get_operator(t_token *token)
{
	if (token[0].type == T_LOGICAL_OP)
	{
		if (token[0].str[0] == '&')
			return (O_AND);
		else
			return (O_OR);
	}
	else
		return (O_PIPE);
};