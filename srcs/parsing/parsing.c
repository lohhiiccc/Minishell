/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:40:48 by lrio              #+#    #+#             */
/*   Updated: 2024/03/08 23:20:19 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_tree.h"

//todo: ajouter lexpand dans cette fonction
t_tree *parsing(t_vector *env, t_vector *tokens)
{
	t_tree *tree;

	tree = make_tree(ft_vector_get(tokens, 0), env);
	return (tree);
}