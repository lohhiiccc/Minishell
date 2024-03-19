/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:41:16 by lrio              #+#    #+#             */
/*   Updated: 2024/03/05 16:53:46 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "tree.h"

t_tree	*ft_new_tree(void *content, t_node node)
{
	t_tree	*new_tree;

	new_tree = malloc(sizeof(t_tree));
	if (new_tree == NULL)
		return (NULL);
	new_tree->type = node;
	new_tree->structur = content;
	new_tree->left = NULL;
	new_tree->right = NULL;
	return (new_tree);
}
