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

#include "add_tree.h"

extern int	g_sig_value;

//todo: si new == NULL free root et return NULL

t_tree	*add_in_subtree(t_tree *root, t_tree *new)
{
	if (root == NULL)
		return (new);
	if (root->type == CMD)
		return (add_up_right(root, new));
	if (is_l_operator(root->type) || root->type == O_PIPE)
	{
		if (is_l_operator(new->type))
			return (add_up_right(root, new));
		return (down_right(root, root, new));
	}
	if (is_redirection(root->type))
	{
		if (new->type == CMD)
			return (down_left(root, root, new));
		if (is_redirection(new->type))
			return (add_redirection(root, new));
		return (add_up_right(root, new));
	}
	return (root);
}
