/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:00:13 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 21:58:50 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "make_tree.h"

static t_tree	*down(t_tree *root, t_tree *new);
static t_tree	*add_subpipe(size_t *i, t_tree *root, t_tree *subroot,
					t_token *tokens);
static t_tree	*make_subtree(t_token *tokens, t_env *env, t_tree *root,
					size_t *i);
static t_tree	*add_subredirection(size_t *i, t_tree *root, t_tree *subroot,
					t_token *tokens);

//todo: check makecommand makeoperator ou makeredirection
t_tree	*make_tree(t_token *tokens, t_env *env)
{
	size_t	i;
	t_tree	*root;

	root = NULL;
	i = 0;
	while (tokens[i].type != T_NEWLINE)
	{
		if (T_CMD == tokens[i].type)
			root = add_in_subtree(root, make_command(tokens + i, env, root));
		else if (T_LOGICAL_OP == tokens[i].type || T_PIPE == tokens[i].type)
			root = add_in_subtree(root, make_operator(tokens + i, root));
		else if (T_RED_OUT == tokens[i].type || T_RED_IN == tokens[i].type)
			root = add_in_subtree(root, make_redirection(tokens + i, root));
		else if (T_PARENTHESE_OP == tokens[i].type)
		{
			i++;
			root = make_subtree(tokens, env, root, &i);
		}
		i++;
	}
	return (root);
}

static t_tree	*make_subtree(t_token *tokens,
							t_env *env, t_tree *root, size_t *i)
{
	t_tree	*subroot;

	subroot = NULL;
	while (T_NEWLINE != tokens[*i].type && T_PARENTHESE_CL != tokens[*i].type)
	{
		if (T_CMD == tokens[*i].type)
			subroot = add_in_subtree(subroot,
					make_command(tokens + *i, env, root));
		else if (T_LOGICAL_OP == tokens[*i].type || T_PIPE == tokens[*i].type)
			subroot = add_in_subtree(subroot, make_operator(tokens + *i, root));
		else if (T_RED_OUT == tokens[*i].type || T_RED_IN == tokens[*i].type)
			subroot = add_in_subtree(subroot,
					make_redirection(tokens + *i, root));
		else if (T_PARENTHESE_OP == tokens[*i].type)
		{
			++*i;
			subroot = make_subtree(tokens, env, subroot, i);
		}
		++*i;
	}
	if ((tokens[*i].type != T_NEWLINE && tokens[*i + 1].type == T_RED_OUT))
		return (add_subredirection(i, root, subroot, tokens));
	else if ((tokens[*i].type != T_NEWLINE && tokens[*i + 1].type == T_PIPE))
		return (add_subpipe(i, root, subroot, tokens));
	return (down(root, subroot));
}

static t_tree	*add_subpipe(size_t *i,
					t_tree *root, t_tree *subroot, t_token *tokens)
{
	t_tree	*new;

	++*i;
	new = make_operator(tokens + *i, root);
	new->left = subroot;
	return (down(root, new));
}

static t_tree	*add_subredirection(size_t *i,
					t_tree *root, t_tree *subroot, t_token *tokens)
{
	t_tree	*new;

	++*i;
	new = make_redirection(tokens + *i, root);
	new->left = subroot;
	return (down(root, new));
}

static t_tree	*down(t_tree *root, t_tree *new)
{
	if (NULL == root)
		return (new);
	if (root->left == NULL)
	{
		root->left = new;
		return (root);
	}
	root->right = new;
	return (root);
}
