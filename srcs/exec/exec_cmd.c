/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:37:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/07 22:35:40 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
#include "ft_printf.h"
#include "expand.h"
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

static void	dup_fd(t_tree *tree, t_vector *fd1, t_vector *fd2, int new_fd);
static int	exec_child_cmd(t_tree *tree, t_fds *fds);

int	exec_cmd(t_tree *tree, t_fds *fds)
{
	int		ret;

	((t_cmd *)tree->structur)->arg = expand_cmd(((t_cmd *) tree->structur)->arg,
			   ((t_cmd *) tree->structur)->env); //todo: securiser ca
	if (is_build_in(((t_cmd *)tree->structur)->arg[0]))
		ret = exec_build_in(tree, fds);
	else
	{
		((t_cmd *)tree->structur)->path = find_path(((t_cmd *)tree->structur)
				->arg[0], &((t_cmd *)tree->structur)->env->env);
		if (!((t_cmd *)tree->structur)->path)
		{
			ft_dprintf(2, "Minichell: %s: Command not found\n",
				((t_cmd *)tree->structur)->arg[0]);
			ret = 127;
		}
		else
		{
			ret = exec_child_cmd(tree, fds);
			free(((t_cmd *)tree->structur)->path);
		}
	}
	return (ret);
}

static void	dup_fd(t_tree *tree, t_vector *fd1, t_vector *fd2, int new_fd)
{
	if (fd1->nbr_elem > 0)
	{
		if (dup2(*(int *)ft_vector_get(fd1, fd1->nbr_elem - 1), new_fd)
			== -1)
		{
			ft_dprintf(2, "Minichell: %s: %s\n",
				((t_cmd *)tree->structur)->arg[0], strerror(errno));
			clean_exit(tree->root, fd1, fd2, 1);
		}
	}
}

static int	exec_child_cmd(t_tree *tree, t_fds *fds)
{
	int	pid;
	int	ret;

	pid = fork();
	if (pid == -1)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			((t_cmd *)tree->structur)->arg[0], strerror(errno));
		return (1);
	}
	if (pid == 0)
	{
		dup_fd(tree, &fds->fd_in, &fds->fd_out, STDIN_FILENO);
		dup_fd(tree, &fds->fd_out, &fds->fd_in, STDOUT_FILENO);
		close_vector_fd(&fds->fd_in);
		close_vector_fd(&fds->fd_out);
		execve(((t_cmd *)tree->structur)->path, ((t_cmd *)tree->structur)->arg,
			ft_vector_get(&((t_cmd *)tree->structur)->env->env, 0));
		ft_dprintf(2, "Minichell: %s: %s\n",
			((t_cmd *)tree->structur)->arg[0], strerror(errno));
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
	}
	waitpid(pid, &ret, 0);
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	return (1);
}
