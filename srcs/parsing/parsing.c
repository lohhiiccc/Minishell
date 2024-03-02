/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:40:48 by lrio              #+#    #+#             */
/*   Updated: 2024/03/02 03:52:39 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tree.h"
#include "libft.h"

/*
 * (ls || cat) > "file"
 * 3-2-8-2-4-6-1
 * 1 1 1 1 1 0 0
 *
 * (ls || ((cat && rm out) > test)) | grep ls
 * 3-2-8-3-3-2-8-3-3-4-6-2-4-4-7-2-2
 * 1 1 1 2 3 3 3 3 3 2 2 2 1 0 0 0 0
 *
 *
 * (ls || ((cat && rm out) > test)) | grep ls
 * (ls || ((cat && rm out) > test))
 * ((cat && rm out) > test)
 * (cat && rm out)
 *
 */
//
//static int redirect_out(t_vector *vector, t_tree *tree, size_t i);
//static int redirect_in(t_vector *vector, t_tree *tree, size_t i);
//t_tree *parsing(t_vector *tokens)
//{
//
//}
//
//t_tree *make_tree(t_vector *vector, int i)
//{
//	t_tree	*tree;
//
//	tree = ft_new_tree(NULL);
//	if (NULL == tree)
//		return (NULL);
//
//	if (((t_token *)vector->addr)[i].type == T_RED_OUT)
//		redirect_out(vector, tree, i);
//	if (((t_token *)vector->addr)[i].type == T_RED_IN)
//		redirect_in(vector, tree, i);
//}
//
//static int redirect_out(t_vector *vector, t_tree *tree, size_t i)
//{
//	enum e_redirect *test;
//
//	test = malloc(sizeof(enum e_redirect)); //todo: secure ca;
//	if (NULL == test)
//		return (-1);
//	tree->type = REDIRECT;
//	if (2 == ft_strlen(((t_token *)vector->addr)[i].str))
//		*test = APPEND;
//	else
//		*test = OUTPUT;
//	tree->structur = test;
//	tree->right = ft_new_tree(((t_token *)vector->addr)[i + 1].str);
//	return (0);
//}
//static int redirect_in(t_vector *vector, t_tree *tree, size_t i)
//{
//	enum e_redirect *test;
//
//	test = malloc(sizeof(enum e_redirect)); //todo: secure ca;
//	if (NULL == test)
//		return (-1);
//	tree->type = REDIRECT;
//	if (2 == ft_strlen(((t_token *)vector->addr)[i].str))
//		*test = HERE_DOC;
//	else
//		*test = INPUT;
//	tree->structur = test;
//	return (0);
//}