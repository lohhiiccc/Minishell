/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:32:18 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/29 19:04:00 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "exec.h"

extern int	g_sig_value;

int	exec_or(t_tree *tree, t_fds *fds, t_param *param)
{
	int	ret;

	ret = exec_args(tree->left, fds, tree->root, param);
	if (ret != 0 && g_sig_value != SIGINT)
		ret = exec_args(tree->right, fds, tree->root, param);
	return (ret);
}
