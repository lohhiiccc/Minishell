/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:21:20 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 22:21:29 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_TREE_H
# define ADD_TREE_H

# include "make_tree.h"

t_tree	*add_redirection(t_tree *root, t_tree *new);
t_tree	*add_down(t_tree *root, t_tree **branch, t_tree *leaf);
t_tree	*add_up_right(t_tree *root, t_tree *new);
t_tree	*down_left(t_tree *root, t_tree *branch, t_tree *new);
t_tree	*down_right(t_tree *root, t_tree *branch, t_tree *new);

#endif