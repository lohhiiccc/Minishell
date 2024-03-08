/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:28:59 by lrio              #+#    #+#             */
/*   Updated: 2024/03/09 00:46:46 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "make_tree.h"
static t_tree *add_down(t_tree *root, t_tree **branch, t_tree *leaf);
static t_tree *add_up_right(t_tree *root, t_tree *new);

t_tree *add_tree(t_tree *root, t_tree *new)
{
	if (NULL == root)
		return (new);
	if ((root->type != CMD && !is_operator(new->type))
		|| root->type == O_PIPE)
	{
		if (root->left == NULL)
			return (add_down(root, &root->left, new));
		if (root->right == NULL)
			return (add_down(root, &root->right, new));
	}
	return (add_up_right(root, new));
//	if (root->left == NULL)
//	{
//		printf("/");
//		return (add_down(root, &root->left, new));
//	}
//	if (root->right == NULL)
//	{
//		printf("\\");
//		return (add_down(root, &root->right, new));
//	}
	return (add_up_right(root, new));
}

static t_tree *add_up_right(t_tree *root, t_tree *new)
{
	printf("|");
	new->left = root;
	return (new);
}

static t_tree *add_down(t_tree *root, t_tree **branch, t_tree *leaf)
{
	*branch = add_tree(*branch, leaf);
	return (root);
}