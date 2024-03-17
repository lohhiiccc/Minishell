/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:31:17 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 23:57:50 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "tree.h"

int prompt(t_vector *env);
//t_tree *prompt(t_vector *env);
int		lexer(char *str, struct s_vector *tokens);
t_tree *parsing(t_vector *env, t_vector *tokens);
#endif