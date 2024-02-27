/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:12:01 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/22 15:46:06 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_join_tree(t_tree *left, t_tree *right, void *content)
{
	t_tree	*tree;

	tree = ft_new_tree(content);
	tree->left = left;
	tree->right = right;
	return (tree);
}
