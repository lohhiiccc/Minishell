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
#include "add_tree.h"

t_tree	*add_in_subtree(t_tree *root, t_tree *new)
{
	if (NULL == root)
		return (new);
	if (CMD == root->type)
		return (add_up_right(root, new));
	if (is_operator(root->type) || O_PIPE == root->type)
	{
		if (is_operator(new->type) || O_PIPE == new->type)
			return (add_up_right(root, new));
		return (down_right(root, root, new));
	}
	if (is_redirection(root->type))
	{
		if (CMD == new->type)
			return (down_left(root, root, new));
		if (is_redirection(new->type))
			return (add_redirection(root, new));
		return (add_up_right(root, new));
	}
	return (root);
}

