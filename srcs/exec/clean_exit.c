/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:01:13 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/17 16:55:25 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void	clean_exit(t_tree *tree, t_vector *fd_in, t_vector *fd_out, int status)
{
	perror(((t_cmd *)tree->structur)->arg[0]);
	ft_clean_tree(tree);
	close_vector_fd(fd_in);
	close_vector_fd(fd_out);
	exit(status);
}
