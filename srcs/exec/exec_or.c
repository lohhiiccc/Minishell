/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:32:18 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/07 01:45:05 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_or(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	ret;

	ret = exec_args(tree->left, fd_in, fd_out);
	if (ret != 0)
		ret = exec_args(tree->right, fd_in, fd_out);
	return (ret);
}
