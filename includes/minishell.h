/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:31:17 by lrio              #+#    #+#             */
/*   Updated: 2024/04/06 16:55:39 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "tree.h"
# include "env.h"

int		prompt(t_env *env);
int lexer(char *str, t_vector *tokens, t_env *env);
t_tree	*parsing(t_env *env, t_vector *tokens);
#endif