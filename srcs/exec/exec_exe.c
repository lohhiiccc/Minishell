/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:03:23 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/03 01:02:05 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

static int	create_child(t_tree *tree, t_fds *fds, t_param *param);
static void	dup_fd(t_tree *tree, t_vector *fd1, t_vector *fd2, int new_fd);
static void	exec_in_child(t_tree *tree, t_fds *fds, t_param *param);
static void	dup_cmd(t_tree *tree, t_cmd *dest, t_fds *fds);

int	exec_exe(t_tree *tree, t_fds *fds, t_param *param)
{
	struct stat	file;
	int			ret;

	stat(((t_cmd *)tree->structur)->path, &file);
	if (S_ISDIR(file.st_mode))
	{
		ft_dprintf(STDERR_FILENO, IS_DIR, ((t_cmd *)tree->structur)->arg[0]);
		ret = 126;
	}
	else if (!S_ISREG(file.st_mode))
	{
		ft_dprintf(STDERR_FILENO, IS_NOT_FILE,
			((t_cmd *)tree->structur)->arg[0]);
		ret = 127;
	}
	else
		ret = create_child(tree, fds, param);
	if (param->is_main == 0)
	{
		if (g_sig_value == SIGINT)
			ft_printf("\n");
		if (g_sig_value == SIGQUIT)
			ft_printf("Quit (core dumped)\n");
	}
	return (ret);
}

static int	create_child(t_tree *tree, t_fds *fds, t_param *param)
{
	int		pid;
	int		ret;

	ms_signal_main_wait();
	pid = fork();
	if (pid == -1)
	{
		ft_dprintf(STDERR_FILENO, ERROR_MSG,
			((t_cmd *)tree->structur)->arg[0], strerror(errno));
		return (1);
	}
	if (pid == 0)
		exec_in_child(tree, fds, param);
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

static void	exec_in_child(t_tree *tree, t_fds *fds, t_param *param)
{
	t_cmd	temp;

	ms_signal_child();
	dup_fd(tree, &fds->fd_in, &fds->fd_out, STDIN_FILENO);
	dup_fd(tree, &fds->fd_out, &fds->fd_in, STDOUT_FILENO);
	close_vector_fd(&fds->fd_in);
	close_vector_fd(&fds->fd_out);
	dup_cmd(tree, &temp, fds);
	free(((t_cmd *)tree->structur)->path);
	ft_clean_tree(tree->root);
	execve(temp.path, temp.arg, ft_vector_get(&param->env, 0));
	ft_dprintf(STDERR_FILENO, ERROR_MSG,
		temp.arg[0], strerror(errno));
	free(temp.path);
	ft_free_tab(temp.arg);
	clear_env(&param->env);
	clean_exit(NULL, &fds->fd_in, &fds->fd_out, 1);
}

static void	dup_cmd(t_tree *tree, t_cmd *dest, t_fds *fds)
{
	dest->path = ft_strdup(((t_cmd *)tree->structur)->path);
	if (!dest->path)
	{
		ft_dprintf(STDERR_FILENO, ERROR_MSG,
			((t_cmd *)tree->structur)->arg[0], strerror(errno));
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
	}
	dest->arg = ft_tabdup(((t_cmd *)tree->structur)->arg);
	if (!dest->arg)
	{
		free(dest->path);
		ft_dprintf(STDERR_FILENO, ERROR_MSG,
			((t_cmd *)tree->structur)->arg[0], strerror(errno));
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
	}
}

static void	dup_fd(t_tree *tree, t_vector *fd1, t_vector *fd2, int new_fd)
{
	if (fd1->nbr_elem > 0)
	{
		if (dup2(*(int *)ft_vector_get(fd1, fd1->nbr_elem - 1), new_fd)
			== -1)
		{
			ft_dprintf(STDERR_FILENO, ERROR_MSG,
				((t_cmd *)tree->structur)->arg[0], strerror(errno));
			clean_exit(tree->root, fd1, fd2, 1);
		}
	}
}
