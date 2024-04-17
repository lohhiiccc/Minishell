/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:40:48 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 21:55:42 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "make_tree.h"

t_tree	*parsing(t_env *env, t_vector *tokens)
{
	t_tree	*tree;

	tree = make_tree(ft_vector_get(tokens, 0), env);
	free_token(tokens);
	return (tree);
}
