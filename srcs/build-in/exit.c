/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/18 04:06:16 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "exec.h"
#include <stdlib.h>

int	ft_exit(t_tree *tree, t_vector *fd_in, t_vector *fd_out, int status)
{
	ft_clean_tree(tree);
	close_vector_fd(fd_in);
	close_vector_fd(fd_out);
	exit(status);
}
