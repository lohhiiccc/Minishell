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

//static size_t	cmd_count(t_token *tokens);

t_tree	*make_tree(t_token *tokens, char **env)
{
	return make_subtree(tokens, env);
}

t_tree *make_subtree(t_token *tokens, char **env)
{
	size_t	i;
	t_tree	*root;

	i = 0;
	root = NULL;
	while (T_NEWLINE != tokens[i].type && T_PARENTHESE_CL != tokens[i].type)
	{
		if (T_CMD == tokens[i].type)
			root = add_in_subtree(root, make_command(tokens + i, env));
		else if (T_LOGICAL_OP == tokens[i].type || T_PIPE == tokens[i].type)
			root = add_in_subtree(root, make_operator(tokens + i));
		else if (T_RED_OUT == tokens[i].type || T_RED_IN == tokens[i].type)
			root = add_in_subtree(root, make_redirection(tokens + i));
		i++;
	}
	return (root);
}

//static size_t	cmd_count(t_token *tokens)
//{
//	size_t	i;
//	size_t	count;
//
//	i = 0;
//	count = 0;
//	while (tokens[i].type != T_NEWLINE)
//	{
//		if (tokens[i].type == T_PARENTHESE_OP)
//			count++;
//		i++;
//	}
//	return (count);
//}