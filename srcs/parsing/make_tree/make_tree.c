/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:00:13 by lrio              #+#    #+#             */
/*   Updated: 2024/03/13 17:37:57 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "make_tree.h"


static t_tree	*add_down(t_tree *root, t_tree **branch, t_tree *leaf);
static t_tree	*down(t_tree *root, t_tree *branch, t_tree *new);

t_tree	*make_tree(t_token *tokens, t_vector *env)
{
	size_t	i;
	t_tree *root;
	(void )env;
	root = NULL;
	i = 0;
	while (tokens[i].type != T_NEWLINE)
	{
		if (T_CMD == tokens[i].type)
			root = add_in_subtree(root, make_command(tokens + i, env));
		else if (T_LOGICAL_OP == tokens[i].type || T_PIPE == tokens[i].type)
			root = add_in_subtree(root, make_operator(tokens + i));
		else if (T_RED_OUT == tokens[i].type || T_RED_IN == tokens[i].type)
			root = add_in_subtree(root, make_redirection(tokens + i));
		else if (T_PARENTHESE_OP == tokens[i].type)
		{
			i++;
			root = make_subtree(tokens, env, root, &i);
		}
		i++;
	}
	return (root);
}

//todo: check makecommand makeoperator ou makeredirection
t_tree *make_subtree(t_token *tokens, t_vector *env, t_tree *root, size_t *i)
{
	t_tree	*subroot;

	root = NULL;
	while (T_NEWLINE != tokens[*i].type && T_PARENTHESE_CL != tokens[*i].type)
	{
		if (T_CMD == tokens[*i].type)
			subroot = add_in_subtree(subroot, make_command(tokens + *i, env));
		else if (T_LOGICAL_OP == tokens[*i].type || T_PIPE == tokens[*i].type)
			subroot = add_in_subtree(subroot, make_operator(tokens + *i));
		else if (T_RED_OUT == tokens[*i].type || T_RED_IN == tokens[*i].type)
			subroot = add_in_subtree(subroot, make_redirection(tokens + *i));
		else if (T_PARENTHESE_OP == tokens[*i].type)
		{
			(*i)++;
			subroot = make_subtree(tokens, env,  subroot, i);
		}
		(*i)++;
	}
	root = down(root, root, subroot);
	return (root);
}

static t_tree	*down(t_tree *root, t_tree *branch, t_tree *new)
{
	if (branch->left == NULL)
		return (add_down(root, &branch->left, new));
	if (branch->right == NULL)
		return (add_down(root, &branch->right, new));
	return (down(root, branch->right, new));
}

static t_tree	*add_down(t_tree *root, t_tree **branch, t_tree *leaf)
{
	*branch = add_in_subtree(*branch, leaf);
	return (root);
}