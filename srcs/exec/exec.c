/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:16:15 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/07 01:44:13 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Executer commande de l'arbre de bas gauche vers droite.
*/

#include "exec.h"
#include <stdio.h>
#include <sys/wait.h>

int	exec_args(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int				ret;

	if (tree->type == O_OR)
		ret = exec_or(tree, fd_in, fd_out);
	if (tree->type == O_AND)
		ret = exec_and(tree, fd_in, fd_out);
	if (tree->type == O_PIPE)
		ret = exec_pipe(tree, fd_in, fd_out);
	if (tree->type == HERE_DOC)
		ret = exec_here_doc(tree, fd_in, fd_out);
	if (tree->type == APPEND)
		ret = exec_apend(tree, fd_in, fd_out);
	if (tree->type == OUTPUT)
		ret = exec_output(tree, fd_in, fd_out);
	if (tree->type == INPUT)
		ret = exec_input(tree, fd_in, fd_out);
	if (tree->type == CMD)
		ret = exec_cmd(tree, fd_in, fd_out);
	return (ret);
}
