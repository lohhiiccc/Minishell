/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:15:50 by lrio              #+#    #+#             */
/*   Updated: 2024/03/07 00:26:00 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAKE_TREE_H
# define MAKE_TREE_H
#include "tree.h"
#include "token.h"
t_tree *make_tree(t_vector *tokens);

t_tree	*make_command(t_vector *tokens);
t_tree *make_operator(t_vector *tokens);
t_tree	*make_redirection(t_vector *tokens);

#endif