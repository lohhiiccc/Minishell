/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:00:13 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 13:15:14 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "make_tree.h"

t_tree	*make_sub(t_token *tokens)
{
	size_t	i;
	t_tree	*root;

	i = 0;
	root = NULL;
	while (tokens[i].type != T_NEWLINE && tokens[i].type != T_PARENTHESE_CL)
	{
		if (tokens[i].type == T_CMD)
			root = add_tree(root, make_command(tokens + i));
		else if (tokens[i].type == T_LOGICAL_OP
				|| tokens[i].type == T_PIPE)
			root = add_tree(root, make_operator(tokens + i));
		else if (tokens[i].type == T_RED_IN
				|| tokens[i].type == T_RED_OUT)
			root = add_tree(root, make_redirection(tokens + i));
		i++;
	}
	return (root);
}
