/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:04:52 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 17:57:28 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree	*ft_join_tree(t_tree *left, t_tree *right, void *content, t_node node)
{
	t_tree	*tree;

	tree = ft_new_tree(content, node, NULL);
	tree->type = node;
	tree->left = left;
	tree->right = right;
	return (tree);
}
