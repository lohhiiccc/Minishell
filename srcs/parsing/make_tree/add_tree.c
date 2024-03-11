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
static t_tree	*down(t_tree *root, t_tree *new);

/*
 * si new == operator : up
 * si new == cmd: down
 * si new == redirection && root == cmd : up
 * si new == redirection && (root == operator) : down
 */
t_tree	*add_tree(t_tree *root, t_tree *new)
{
	if (NULL == root)
		return (new);
	if (is_operator(new->type))
		return (add_up_right(root, new));
	if (new->type == CMD)
		return (down(root, new));
	if (is_redirection(new->type) && root->type == CMD)
		return (add_up_right(root, new));
	if (is_redirection(new->type) && is_redirection(root->type))
		return (add_up_right(root, new));
	if (is_redirection(new->type) && (is_operator(root->type)))
		return (down(root, new));
	return (add_up_right(root, new));
}

static t_tree	*add_up_right(t_tree *root, t_tree *new)
{
	printf("|");
	new->left = root;
	return (new);
}

static t_tree	*down(t_tree *root, t_tree *new)
{
	if (root->left == NULL)
		return (add_down(root, &root->left, new));
	return (add_down(root, &root->right, new));
}

static t_tree	*add_down(t_tree *root, t_tree **branch, t_tree *leaf)
{
	*branch = add_tree(*branch, leaf);
	return (root);
}
