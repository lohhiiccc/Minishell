/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:35:59 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/08 03:45:18 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <fcntl.h>

int	exec_here_doc(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	fd;
	int	ret;

	fd = open((char *)tree->structur, O_RDONLY);
	if (fd == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	unlink((char *)tree->structur);
	ft_vector_add(fd_in, &fd);
	ret = exec_args(tree->left, fd_in, fd_out);
	if (close(fd) == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	ft_vector_delete_elem(fd_in, fd_in->nbr_elem);
	return (ret);
}
