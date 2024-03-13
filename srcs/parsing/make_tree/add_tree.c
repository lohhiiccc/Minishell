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
static t_tree	*down_left(t_tree *root, t_tree *branch,t_tree *new);
static t_tree	*down_right(t_tree *root, t_tree *branch,t_tree *new);

t_tree	*add_tree(t_tree *root, t_tree *new)
{
	if (NULL == root)
		return (new);
	print_tree(root);
	printf("\n------------------------------------\n");
	if (CMD == root->type)
	{
		printf("test1-->%d", root->type);
		return (add_up_right(root,new));
	}
	if (is_operator(root->type) || O_PIPE == root->type)
	{
		printf("test2-->%d", root->type);
		if (is_operator(new->type) || O_PIPE == new->type)
			return (add_up_right(root, new));
		return (down_right(root, root, new));
	}
	if (is_redirection(root->type))
	{
		printf("test3-->%d", root->type);
		if (CMD == new->type)
			return (down_left(root, root, new));
		return (add_up_right(root, new));
	}
	return (root);
}

static t_tree	*add_up_right(t_tree *root, t_tree *new)
{
	new->left = root;
	return (new);
}

static t_tree	*down_right(t_tree *root, t_tree *branch,t_tree *new)
{
	t_tree *tmp;
	(void)branch;
//	if (branch->right == NULL)
//		return (add_down(root, &branch->right, new));
	if (new->type == CMD)
		return add_down(root, &branch->right, new);
	tmp = root->right;
	root->right = new;
	new->left = tmp;
	return (root);
//	return (down_left(root, branch->right, new));
//	branch->left = add_up_right(root, new);//TODO: insserer entre root et branch->right new
}

static t_tree	*down_left(t_tree *root,t_tree *branch, t_tree *new)
{
	if (branch->left == NULL)
		return (add_down(root, &branch->left, new));
	return (down_left(root, branch->left, new));
}

static t_tree	*add_down(t_tree *root, t_tree **branch, t_tree *leaf)
{
	*branch = add_tree(*branch, leaf);
	return (root);
}
