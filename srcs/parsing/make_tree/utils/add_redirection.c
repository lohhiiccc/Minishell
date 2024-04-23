/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:00:10 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 22:00:20 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "add_tree.h"

t_tree	*add_redirection(t_tree *root, t_tree *new)
{
	t_tree	*tmp;
	t_tree	*tmp2;

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
