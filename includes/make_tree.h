/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:15:50 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 23:58:19 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_TREE_H
# define MAKE_TREE_H
# include "tree.h"
# include "token.h"
# include <stdint.h>

t_tree			*make_tree(t_token *tokens, t_vector *env);
t_tree			*make_command(t_token *tokens, t_vector *env, t_tree *root);
t_tree			*make_operator(t_token *tokens, t_tree *root);
t_tree			*make_redirection(t_token *tokens, t_tree *root);
t_tree			*add_in_subtree(t_tree *root, t_tree *new);
uint8_t			is_redirection(t_node root_type);
uint8_t			is_operator(t_node root_type);
#endif