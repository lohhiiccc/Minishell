/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:03:23 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/25 17:27:39 by mjuffard         ###   ########lyon.fr   */
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

static int	exec_child_cmd(t_tree *tree, t_fds *fds, t_env *env);
static void	print_error(t_tree *tree, char *error);
static void	dup_fd(t_tree *tree, t_vector *fd1, t_vector *fd2, int new_fd);

int	exec_exe(t_tree *tree, t_fds *fds, t_env *env)
{
	int			ret;
	struct stat	file;

	((t_cmd *)tree->structur)->path = find_path(((t_cmd *)tree->structur)
			->arg[0], &env->env);
	if (!((t_cmd *)tree->structur)->path)
	{
		ft_dprintf(2, "Minichel: %s: Command not found\n",
			((t_cmd *)tree->structur)->arg[0]);
		ret = 127;
	}
	else
	{
		stat(((t_cmd *)tree->structur)->path, &file);
		if (S_ISDIR(file.st_mode))
		{
			ft_dprintf(2, "Minichel: %s: Is a directory\n",
				((t_cmd *)tree->structur)->arg[0]);
			ret = 126;
		}
		else
			ret = exec_child_cmd(tree, fds, env);
		free(((t_cmd *)tree->structur)->path);
		if (0 == env->is_main)
		{
			if (g_sig_value == SIGINT)
				ft_printf("\n");
			if (g_sig_value == SIGQUIT)
				ft_printf("Quit (core dumped)\n");
		}
	}
	return (ret);
}

static int	exec_child_cmd(t_tree *tree, t_fds *fds, t_env *env)
{
	int		pid;
	int		ret;
	t_cmd	temp;

	ms_signal_main_wait();
	pid = fork();
	if (-1 == pid)
	{
		print_error(tree, strerror(errno));
		return (1);
	}
	if (0 == pid)
	{
		ms_signal_child();
		dup_fd(tree, &fds->fd_in, &fds->fd_out, STDIN_FILENO);
		dup_fd(tree, &fds->fd_out, &fds->fd_in, STDOUT_FILENO);
		close_vector_fd(&fds->fd_in);
		close_vector_fd(&fds->fd_out);
		temp.path = ft_strdup(((t_cmd *)tree->structur)->path);
		if (!temp.path)
		{
			print_error(tree, strerror(errno));
			clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
		}
		temp.arg = ft_tabdup(((t_cmd *)tree->structur)->arg);
		if (!temp.arg)
		{
			free(temp.path);
			print_error(tree, strerror(errno));
			clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
		}
		ft_clean_tree(tree->root);
		execve(temp.path, temp.arg,
			ft_vector_get(&env->env, 0));
		print_error(tree, strerror(errno));
		free(temp.path);
		ft_free_tab(temp.arg);
		clean_exit(NULL, &fds->fd_in, &fds->fd_out, 1);
	}
	if (waitpid(pid, &ret, 0) == -1)
		ft_printf("%s\n", strerror(errno));
	if (WIFEXITED(ret))
	{
		g_sig_value = 0;
		return (WEXITSTATUS(ret));
	}
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
			ft_dprintf(2, "Minichel: %s: %s\n",
				((t_cmd *)tree->structur)->arg[0], strerror(errno));
			clean_exit(tree->root, fd1, fd2, 1);
		}
	}
}

static void	print_error(t_tree *tree, char *error)
{
	ft_dprintf(2, "Minichel: %s: %s\n",
		((t_cmd *)tree->structur)->arg[0], error);
}
