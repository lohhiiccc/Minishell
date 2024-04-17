/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_down_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:59:42 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 21:59:47 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "add_tree.h"

t_tree	*down_left(t_tree *root, t_tree *branch, t_tree *new)
{
	if (branch->left == NULL)
		return (add_down(root, &branch->left, new));
	return (down_left(root, branch->left, new));
}
