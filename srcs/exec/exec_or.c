/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:32:18 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 04:54:58 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
int	exec_or(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	ret;

	ret = exec_args(tree->left, fd_in, fd_out);
	if (ret != 0)
		ret = exec_args(tree->right, fd_in, fd_out);
	return (ret);
}
