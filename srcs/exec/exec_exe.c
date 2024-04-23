/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:03:23 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/22 22:14:45 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include "env.h"
#include "exec.h"
#include "ft_printf.h"
#include "ms_signal.h"

extern int	g_sig_value;

static int	exec_child_cmd(t_tree *tree, t_fds *fds);
static void	print_error(t_tree *tree, char *error);
static void	dup_fd(t_tree *tree, t_vector *fd1, t_vector *fd2, int new_fd);

int	exec_exe(t_tree *tree, t_fds *fds, t_env *env)
{
	int			ret;
	struct stat	file;

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
		stat(((t_cmd *)tree->structur)->path, &file);
		if (S_ISDIR(file.st_mode))
		{
			ft_dprintf(2, "Minichell: %s: Is a directory\n",
				((t_cmd *)tree->structur)->arg[0]);
			ret = 126;
		}
		else
			ret = exec_child_cmd(tree, fds);
		free(((t_cmd *)tree->structur)->path);
		if (env->is_main == 0)
		{
			if (g_sig_value == SIGINT)
				ft_printf("\n");
			if (g_sig_value == SIGQUIT)
				ft_printf("Quit (core dumped)\n");
		}
	}
	return (ret);
}

static int	exec_child_cmd(t_tree *tree, t_fds *fds)
{
	int	pid;
	int	ret;

	pid = fork();
	ms_signal_main_wait();
	if (pid == -1)
	{
		print_error(tree, strerror(errno));
		return (1);
	}
	if (pid == 0)
	{
		ms_signal_child();
		dup_fd(tree, &fds->fd_in, &fds->fd_out, STDIN_FILENO);
		dup_fd(tree, &fds->fd_out, &fds->fd_in, STDOUT_FILENO);
		close_vector_fd(&fds->fd_in);
		close_vector_fd(&fds->fd_out);
		execve(((t_cmd *)tree->structur)->path, ((t_cmd *)tree->structur)->arg,
			ft_vector_get(&((t_cmd *)tree->structur)->env->env, 0));
		print_error(tree, strerror(errno));
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
	}
	if (waitpid(pid, &ret, 0) == -1)
		ft_printf("%s\n", strerror(errno));
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	else if (__WIFSIGNALED(ret))
		return (128 + g_sig_value);
	return (1);
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

static void	print_error(t_tree *tree, char *error)
{
	ft_dprintf(2, "Minichell: %s: %s\n",
		((t_cmd *)tree->structur)->arg[0], error);
}
