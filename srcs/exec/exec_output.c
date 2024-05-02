/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:34:56 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 04:11:07 by mjuffard         ###   ########lyon.fr   */
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

int	exec_output(t_tree *tree, t_fds *fds, t_param *param)
{
	int	fd;
	int	ret;

	tree->structur = expand_file((char *)tree->structur, param);
	if (NULL == (char *)tree->structur)
		return (print_error_status(tree));
	fd = open((char *)tree->structur, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1 || ft_vector_add(&fds->fd_out, &fd) == -1)
		return (print_error_status(tree));
	ret = exec_args(tree->left, fds, tree->root, param);
	ft_vector_delete_elem(&fds->fd_out, fds->fd_out.nbr_elem - 1);
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
