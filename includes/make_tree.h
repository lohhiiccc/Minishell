/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:15:50 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 13:07:13 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_TREE_H
# define MAKE_TREE_H
# include "tree.h"
# include "token.h"

t_tree			*make_sub(t_token *tokens);
t_tree			*make_command(t_token *tokens);
t_tree			*make_operator(t_token *tokens);
t_tree			*make_redirection(t_token *tokens);
t_tree			*add_tree(t_tree *root, t_tree *new);
unsigned char	is_redirection(t_node root_type);
unsigned char	is_operator(t_node root_type);
#endif