/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:32:18 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/19 17:21:25 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_or(t_tree *tree, t_fds *fds)
{
	int	ret;

	ret = exec_args(tree->left, fds, tree->root);
	if (ret != 0)
		ret = exec_args(tree->right, fds, tree->root);
	return (ret);
}
