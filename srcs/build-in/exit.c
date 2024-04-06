/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:18:52 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/04 19:48:41 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
#include "vector.h"
#include <stdlib.h>

void	ft_exit(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	clear_env(((t_cmd *)tree->structur)->env.env);
	if (((t_cmd *)tree->structur)->arg[1])
		clean_exit(tree->root, fd_in, fd_out,
			ft_atoi(((t_cmd *)tree->structur)->arg[1]));
	else
		clean_exit(tree->root, fd_in, fd_out,
			((t_cmd *)tree->structur)->env.ret);
}
