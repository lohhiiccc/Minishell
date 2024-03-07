/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:37:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/07 01:49:10 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <sys/wait.h>

int	exec_cmd(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	pid;
	int	ret;

	if (!((t_cmd *)tree->structur)->path)
		ret = exec_build_in(((t_cmd *)tree->structur)->arg);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (fd_in->nbr_elem > 0)
				dup2(*(int *)(fd_in->addr + ((fd_in->nbr_elem - 1) * fd_in->size)), STDIN_FILENO);
			if (fd_out->nbr_elem > 0)
				dup2(*(int *)(fd_out->addr + ((fd_out->nbr_elem - 1) * fd_out->size)), STDOUT_FILENO);
			close_vector_fd(fd_in);
			close_vector_fd(fd_out);
			execve(((t_cmd *)tree->structur)->path, ((t_cmd *)tree->structur)->arg, ((t_cmd *)tree->structur)->env);
		}
		waitpid(pid, &ret, 0);
	}
	close_vector_fd(fd_in);
	close_vector_fd(fd_out);
	return (ret);
}
