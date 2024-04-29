/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:16:15 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/25 01:38:12 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Executer commande de l'arbre de bas gauche vers droite.
*/

#include "exec.h"

int	exec_args(t_tree *tree, t_fds *fds, t_tree *root, t_param *param)
{
	int				ret;
	const t_exec	tab[] = {&exec_or, &exec_and, &exec_pipe, &exec_here_doc,
		&exec_apend, &exec_output, &exec_input, &exec_cmd};

	if (!tree)
		return (0);
	if (!root)
		tree->root = tree;
	else
		tree->root = root;
	ret = tab[tree->type](tree, fds, param);
	return (ret);
}
