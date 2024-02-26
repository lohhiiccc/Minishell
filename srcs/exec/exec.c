/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:16:15 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/23 01:16:14 by mjuffard         ###   ########lyon.fr   */
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
	ret = 
}
