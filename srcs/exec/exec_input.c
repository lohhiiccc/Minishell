/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:33:24 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 02:16:27 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "exec.h"
#include "ft_printf.h"
#include "expand.h"

static int	print_error_status(t_tree *tree);

int	exec_input(t_tree *tree, t_fds *fds, t_param *param)
{
	int	fd;
	int	ret;

	tree->structur = expand_file((char *)tree->structur, param);
	if (!(char *)tree->structur)
		return (print_error_status(tree));
	fd = open((char *)tree->structur, O_RDONLY);
	if (fd == -1 || ft_vector_add(&fds->fd_in, &fd) == -1)
		return (print_error_status(tree));
	ret = exec_args(tree->left, fds, tree->root, param);
	ft_vector_delete_elem(&fds->fd_in, fds->fd_in.nbr_elem);
	if (close(fd) == -1)
		return (print_error_status(tree));
	return (ret);
}

static int	print_error_status(t_tree *tree)
{
	ft_dprintf(STDERR_FILENO, ERROR_MSG,
		(char *)tree->structur, strerror(errno));
	return (1);
}
