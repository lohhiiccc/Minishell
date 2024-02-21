/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:16:15 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/21 03:18:45 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Executer commande de l'arbre de bas gauche vers droite.
*/

#include "libft.h"

t_tree	*next_exec(t_tree *tree)
{
	while (tree->left)
		tree = tree->left;
	while (tree->right)
		tree = tree ->right;
	return (tree);
}

void	exec_args(t_tree *tree)
{
	
}
