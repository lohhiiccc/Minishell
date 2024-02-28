/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:16:15 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/28 04:50:13 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Executer commande de l'arbre de bas gauche vers droite.
*/

#include "libft.h"
#include "tree.h"
#include <fcntl.h>

t_tree	*next_exec(t_tree *tree)
{
	while (tree->left)
		tree = tree->left;
	while (tree->right)
		tree = tree ->right;
	return (tree);
}

int	exec_args(t_tree *tree)
{
	static t_vector	*fd_in = NULL;
	static t_vector	*fd_out = NULL;

	if (!fd_in)
		ft_vector_init(fd_in, sizeof(int));
	if (!fd_in)
		ft_vector_init(fd_out, sizeof(int));
	if (tree->type == OPE)
	{
		if ((t_operator *)tree->structur == OR)
			exec_or(tree);
		if ((t_operator *)tree->structur == AND)
			exec_and(tree);
		if ((t_operator *)tree->structur == PIPE)
			exec_pipe(tree, fd_in, fd_out);
	}
	if (tree->type == REDIRECT)
	{
		if ((t_redirect *)tree->structur == HERE_DOC)
			exec_here_doc(tree);
		if ((t_redirect *)tree->structur == APPEND)
			exec_apend(tree, fd_out);
		if ((t_redirect *)tree->structur == OUTPUT)
			exec_output(tree, fd_out);
		if ((t_redirect *)tree->structur == INPUT)
			exec_input(tree, fd_in);
	}
	if (tree->type == CMD)
		exec_cmd(tree, fd_in, fd_out);
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

	fd = open((char *)tree->right, O_RDONLY);
	ft_vector_add(fd_in, fd);
	exec_args(tree->left);
}

int	exec_output(t_tree *tree, t_vector *fd_out)
{
	int	fd;

	fd = open((char *)tree->right, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_vector_add(fd_out, fd);
	exec_args(tree->left);
}

int	exec_apend(t_tree *tree, t_vector *fd_out)
{
	int	fd;

	fd = open((char *)tree->right, O_WRONLY | O_CREAT | O_APPEND, 0644);
	ft_vector_add(fd_out, fd);
	exec_args(tree->left);
}

int	exec_pipe(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	ret;
	int	fd[2];

	if (pipe(fd) == -1)
		return (1);
	ft_vector_add(fd_in, fd[0]);
	ft_vector_add(fd_out, fd[1]);
	exec_args(tree->left);
	exec_args(tree->right);
}
