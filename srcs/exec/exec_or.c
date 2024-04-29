/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:32:18 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/29 19:03:40 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "exec.h"
#include <signal.h>

extern int	g_sig_value;

int	exec_or(t_tree *tree, t_fds *fds, t_env *env)
{
	int	ret;

	ret = exec_args(tree->left, fds, tree->root, env);
	if (ret != 0 && g_sig_value != SIGINT)
		ret = exec_args(tree->right, fds, tree->root, env);
	return (ret);
}
