/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:18:52 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/30 02:51:00 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "exec.h"
#include "env.h"
#include "vector.h"
#include "ft_printf.h"
#include "build_in.h"

void	ft_exit(t_tree *tree, t_vector *fd_in, t_vector *fd_out, t_param *param)
{
	if (((t_cmd *)tree->structur)->arg[2])
	{
		ft_dprintf(STDERR_FILENO, ERR_EXIT_TOO_MANY_ARGS);
		return ;
	}
	clear_env(&param->env);
	if (((t_cmd *)tree->structur)->arg[1])
		clean_exit(tree->root, fd_in, fd_out,
			ft_atoi(((t_cmd *)tree->structur)->arg[1]));
	else
		clean_exit(tree->root, fd_in, fd_out, param->ret);
}
