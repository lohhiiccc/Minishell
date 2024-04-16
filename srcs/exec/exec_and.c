/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:31:25 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/19 17:19:45 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_and(t_tree *tree, t_fds *fds)
{
	int	ret;

	ret = exec_args(tree->left, fds, tree->root);
	if (ret == 0)
		ret = exec_args(tree->right, fds, tree->root);
	return (ret);
}

