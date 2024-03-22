/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:28:59 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 13:17:10 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "make_tree.h"

static t_tree	*add_down(t_tree *root, t_tree **branch, t_tree *leaf);
static t_tree	*add_up_right(t_tree *root, t_tree *new);
static t_tree	*down_left(t_tree *root, t_tree *branch, t_tree *new);
static t_tree	*down_right(t_tree *root, t_tree *branch, t_tree *new);

t_tree	*add_in_subtree(t_tree *root, t_tree *new)
{
	if (NULL == root)
		return (new);
	if (CMD == root->type)
		return (add_up_right(root, new));
	if (is_operator(root->type) || O_PIPE == root->type)
	{
		if (is_operator(new->type) || O_PIPE == new->type)
			return (add_up_right(root, new));
		return (down_right(root, root, new));
	}
	if (is_redirection(root->type))
	{
		if (CMD == new->type)
			return (down_left(root, root, new));
		if (is_redirection(new->type))
		{
			t_tree *tmp;
			t_tree *tmp2;

			tmp = root;
			while (tmp->left && is_redirection(tmp->left->type))
				tmp = tmp->left;
			if (!tmp->left)
				return (down_left(root, root, new));
			tmp2 = tmp->left;
			tmp->left = new;
			new->left = tmp2;
			return (root);
		}
		return (add_up_right(root, new));
	}
	return (root);
}

static t_tree	*add_up_right(t_tree *root, t_tree *new)
{
	new->left = root;
	return (new);
}

static t_tree	*down_right(t_tree *root, t_tree *branch, t_tree *new)
{
	t_tree	*tmp;

	if (new->type == CMD)
		return (add_down(root, &branch->right, new));
	tmp = root->right;
	root->right = new;
	new->left = tmp;
	return (root);
}

static t_tree *down_left(t_tree *root, t_tree *branch, t_tree *new)
{
	if (branch->left == NULL)
		return (add_down(root, &branch->left, new));
	return (down_left(root, branch->left, new));
}

static t_tree	*add_down(t_tree *root, t_tree **branch, t_tree *leaf)
{
	*branch = add_in_subtree(*branch, leaf);
	return (root);
}
