/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:04:52 by lrio              #+#    #+#             */
/*   Updated: 2024/03/01 20:49:00 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree	*ft_join_tree(t_tree *left, t_tree *right, void *content)
{
	t_tree	*tree;

	tree = ft_new_tree(content);
	tree->left = left;
	tree->right = right;
	return (tree);
}
