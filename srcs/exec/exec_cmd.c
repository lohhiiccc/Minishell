/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:37:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 00:40:53 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

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
		execve(((t_cmd *)tree->structur)->path, \
			((t_cmd *)tree->structur)->arg, ft_vector_get(((t_cmd *)tree-> \
				structur)->env, 0));
	}
	waitpid(pid, &ret, 0);
	return (WIFEXITED(ret));
}

int	exec_cmd(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int		ret;

	if (is_build_in(((t_cmd *)tree->structur)->arg[0]))
		ret = exec_build_in(tree->structur);
	else
	{
		((t_cmd *)tree->structur)->path = find_path(((t_cmd *)
					tree->structur)->arg[0], ((t_cmd *)tree->structur)->env);
		if (!((t_cmd *)tree->structur)->path)
		{
			write(2, "NOOB\n", 5);
			return (127);
		}
		else
			ret = exec_child_cmd(tree, fd_in, fd_out);
		free(((t_cmd *)tree->structur)->path);
	}
	return (ret);
}
