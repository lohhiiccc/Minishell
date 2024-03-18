/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:34:56 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 00:37:46 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <fcntl.h>
#include <unistd.h>

int	exec_output(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	fd;
	int	ret;

	fd = open((char *)tree->structur, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	ft_vector_add(fd_out, &fd);
	ret = exec_args(tree->left, fd_in, fd_out);
	if (close(fd))
		clean_exit(tree, fd_in, fd_out, 1);
	ft_vector_delete_elem(fd_out, fd_out->nbr_elem);
	return (ret);
}
