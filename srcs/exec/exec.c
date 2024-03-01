/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:16:15 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/01 18:50:53 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Executer commande de l'arbre de bas gauche vers droite.
*/

#include "libft.h"
#include "tree.h"
#include "exec.h"
#include "build_in.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int	exec_args(t_tree *tree)
{
	static t_vector	*fd_in = NULL;
	static t_vector	*fd_out = NULL;
	int				ret;

	if (!fd_in)
		ft_vector_init(fd_in, sizeof(int));
	if (!fd_out)
		ft_vector_init(fd_out, sizeof(int));
	if (tree->type == OPE)
	{
		if (*(t_operator *)tree->structur == O_OR)
			ret = exec_or(tree);
		if (*(t_operator *)tree->structur == O_AND)
			ret = exec_and(tree);
		if (*(t_operator *)tree->structur == O_PIPE)
			ret = exec_pipe(tree, fd_in, fd_out);
	}
	if (tree->type == REDIRECT)
	{
		if (*(t_redirect *)tree->structur == HERE_DOC)
			ret = exec_here_doc(tree, fd_in);
		if (*(t_redirect *)tree->structur == APPEND)
			ret = exec_apend(tree, fd_out);
		if (*(t_redirect *)tree->structur == OUTPUT)
			ret = exec_output(tree, fd_out);
		if (*(t_redirect *)tree->structur == INPUT)
			ret = exec_input(tree, fd_in);
	}
	if (tree->type == CMD)
		ret = exec_cmd(tree, fd_in, fd_out);
	return (ret);
}

int	exec_or(t_tree *tree)
{
	int	ret;

	ret = exec_args(tree->left);
	if (ret != 0)
		ret = exec_args(tree->right);
	return (ret);
}

int	exec_and(t_tree *tree)
{
	int	ret;

	ret = exec_args(tree->left);
	if (ret == 0)
		ret = exec_args(tree->right);
	return (ret);
}


int	exec_input(t_tree *tree, t_vector *fd_in)
{
	int	fd;
	int	ret;

	fd = open((char *)tree->right, O_RDONLY);
	ft_vector_add(fd_in, &fd);
	ret = exec_args(tree->left);
	close(fd);
	ft_vector_delete_last(fd_in);
	return (ret);
}

int	exec_output(t_tree *tree, t_vector *fd_out)
{
	int	fd;
	int	ret;

	fd = open((char *)tree->right, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_vector_add(fd_out, &fd);
	ret = exec_args(tree->left);
	close(fd);
	ft_vector_delete_last(fd_out);
	return (ret);
}

int	exec_apend(t_tree *tree, t_vector *fd_out)
{
	int	fd;
	int ret;

	fd = open((char *)tree->right, O_WRONLY | O_CREAT | O_APPEND, 0644);
	ft_vector_add(fd_out, &fd);
	ret = exec_args(tree->left);
	close(fd);
	ft_vector_delete_last(fd_out);
	return (ret);
}

int	exec_here_doc(t_tree *tree, t_vector *fd_in)
{
	int	fd;
	int	ret;

	fd = open((char *)tree->right, O_RDONLY);
	unlink((char *)tree->right);
	ft_vector_add(fd_in, &fd);
	ret = exec_args(tree->left);
	close(fd);
	ft_vector_delete_last(fd_in);
	return (ret);
}

int	exec_pipe(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	ret;
	int	fd[2];

	if (pipe(fd) == -1)
		return (1);
	ft_vector_add(fd_out, &fd[1]);
	exec_args(tree->left);
	close(fd[1]);
	ft_vector_delete_last(fd_out);
	ft_vector_add(fd_in, &fd[0]);
	ret = exec_args(tree->right);
	close(fd[0]);
	ft_vector_delete_last(fd_in);
	return (ret);
}

void	close_vector_fd(t_vector *fd)
{
	size_t	i;

	i = 0;
	while (i < fd->nbr_elem)
	{
		close(*(int *)fd->addr + (i * fd->size));
		i++;
	}
	free(fd->addr);
}

int	exec_cmd(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	pid;
	int	ret;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		dup2(*(int *)fd_in->addr + ((fd_in->nbr_elem - 1) * fd_in->size), STDIN_FILENO);
		dup2(*(int *)fd_out->addr + ((fd_out->nbr_elem - 1) * fd_out->size), STDOUT_FILENO);
		close_vector_fd(fd_in);
		close_vector_fd(fd_out);
		if (!((t_cmd *)tree->structur)->path)
			exec_builtin(((t_cmd *)tree->structur)->arg);
		else
			execve(((t_cmd *)tree->structur)->path, ((t_cmd *)tree->structur)->arg, ((t_cmd *)tree->structur)->env);
	}
	waitpid(pid, &ret, 0);
	return (ret);
}

int	exec_builtin(char **arg)
{
	if (!ft_strcmp(arg[0], "echo"))
		ft_echo(arg);
	else if (!ft_strcmp(arg[0], "cd"))
		ft_cd();
	else if (!ft_strcmp(arg[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(arg[0], "export"))
		ft_export();
	else if (!ft_strcmp(arg[0], "unset"))
		ft_unset();
	else if (!ft_strcmp(arg[0], "env"))
		ft_env();
	else if (!ft_strcmp(arg[0], "exit"))
		ft_exit();
	else
	{
		write(2, "NOOB\n", 5);
		return (1);
	}
	return (0);
}

//echo
//cd
//pwd
//export
//unset
//env
//exit

