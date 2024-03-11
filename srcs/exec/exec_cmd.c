/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:37:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/11 19:01:12 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <sys/wait.h>

static int	exec_child_cmd(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	pid;
	int	ret;

	pid = fork();
	if (pid == 0)
	{
		if (fd_in->nbr_elem > 0)
			if (dup2(*(int *)(fd_in->addr + ((fd_in->nbr_elem - 1) \
				* fd_in->size)), STDIN_FILENO))
				clean_exit(tree, fd_in, fd_out, 1);
		if (fd_out->nbr_elem > 0)
			if (dup2(*(int *)(fd_out->addr + ((fd_out->nbr_elem - 1) \
				* fd_out->size)), STDOUT_FILENO) == -1)
				clean_exit(tree, fd_in, fd_out, 1);
		close_vector_fd(fd_in);
		close_vector_fd(fd_out);
		((t_cmd *)tree->structur)->path = find_path(((t_cmd *)tree->structur)->arg[0], ((t_cmd *)tree->structur)->env);
		execve(((t_cmd *)tree->structur)->path, \
			((t_cmd *)tree->structur)->arg, ((t_cmd *)tree->structur)->env);
	}
	waitpid(pid, &ret, 0);
	return (ret);
}

int	exec_cmd(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	ret;

	if (!((t_cmd *)tree->structur)->path)
		ret = exec_build_in(((t_cmd *)tree->structur)->arg);
	else
		ret = exec_child_cmd(tree, fd_in, fd_out);
	close_vector_fd(fd_in);
	close_vector_fd(fd_out);
	return (ret);
}
