/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:41:29 by lrio              #+#    #+#             */
/*   Updated: 2024/02/27 17:44:43 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree	*ft_join_tree(t_tree *left, t_tree *right, void *content)
{
	t_tree	*tree;

	tree = ft_new_tree(content);
	tree->left = left;
	tree->right = right;
	if (left)
		left->structur = tree;
	if (right)
		right->structur = tree;
	return (tree);
}
