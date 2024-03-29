/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:16:15 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/19 17:18:48 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Executer commande de l'arbre de bas gauche vers droite.
*/

#include "exec.h"
#include <stdio.h>

int	exec_args(t_tree *tree, t_vector *fd_in, t_vector *fd_out, t_tree *root)
{
	const t_exec	tab[] = {&exec_or, &exec_and, &exec_pipe, &exec_here_doc,
		&exec_apend, &exec_output, &exec_input, &exec_cmd};
	int				ret;

	if (!root)
		root = tree;
	else
		tree->root = root;
	ret = tab[tree->type](tree, fd_in, fd_out);
//	printf("RET = %d NODE = %d\n", ret, tree->type);
	return (ret);
}
