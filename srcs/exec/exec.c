/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:16:15 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/27 17:31:01 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Executer commande de l'arbre de bas gauche vers droite.
*/

#include "exec.h"

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
	if (tree->type == OPE)
	{
		if ((t_operator *)tree->structur == OR)
			exec_or(tree);
		if ((t_operator *)tree->structur == AND)
			exec_and(tree);
		if ((t_operator *)tree->structur == PIPE)
			exec_pipe(tree);
	}
	if (tree->type == REDIRECT)
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

int	exec_pipe(t_tree *tree)
{
	int	ret;

	exec_args(tree->left);
	exec_args(tree->right);
}
