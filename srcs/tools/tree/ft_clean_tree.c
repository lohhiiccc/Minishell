/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:38:53 by lrio              #+#    #+#             */
/*   Updated: 2024/03/18 04:44:20 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "stdlib.h"

static void	clean_cmd(t_tree *tree)
{
	size_t	i;

	i = 0;
	while (((t_cmd *)tree->structur)->arg[i])
	{
		free(((t_cmd *)tree->structur)->arg[i]);
		i++;
	}
//	if (((t_cmd *)tree->structur)->arg)
	free(((t_cmd *)tree->structur)->arg);
	free(tree->structur);
}

void	ft_clean_tree(t_tree *tree)
{
	if (!tree)
		return ;
	ft_clean_tree(tree->left);
	ft_clean_tree(tree->right);
	if (tree->type == CMD)
		clean_cmd(tree);
	if (tree->type == HERE_DOC || tree->type == APPEND
		|| tree->type == OUTPUT || tree->type == INPUT)
		free(tree->structur);
	free(tree);
}
