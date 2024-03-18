/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:31:25 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 04:55:01 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
int	exec_and(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	ret;

	ret = exec_args(tree->left, fd_in, fd_out);
	if (ret == 0)
		ret = exec_args(tree->right, fd_in, fd_out);
	return (ret);
}
