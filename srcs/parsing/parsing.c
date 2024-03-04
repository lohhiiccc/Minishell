/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:40:48 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 18:12:54 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tree.h"

/*
 *
 * (ls || ((cat && rm out) > test)) | grep ls
 * (ls || ((cat && rm out) > test))
 * ((cat && rm out) > test)
 *  (cat && rm out)
 *
 */
////
////static int redirect_out(t_vector *vector, t_tree *tree, size_t i);
////static int redirect_in(t_vector *vector, t_tree *tree, size_t i);
//t_tree *parsing(t_vector *tokens)
//{
//
//}
