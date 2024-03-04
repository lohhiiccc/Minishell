/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:04:27 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 17:33:27 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "tree.h"
#include "libft.h"

int		exec_args(t_tree *tree, t_vector *fd_in, t_vector *fd_out);
int		exec_or(t_tree *tree, t_vector *fd_in, t_vector *fd_out);
int		exec_pipe(t_tree *tree, t_vector *fd_in, t_vector *fd_out);
int		exec_and(t_tree *tree, t_vector *fd_in, t_vector *fd_out);
int		exec_cmd(t_tree *tree, t_vector *fd_in, t_vector *fd_out);
int		exec_input(t_tree *tree, t_vector *fd_in, t_vector *fd_out);
int		exec_output(t_tree *tree, t_vector *fd_in, t_vector *fd_out);
int		exec_apend(t_tree *tree, t_vector *fd_in, t_vector *fd_out);
int		exec_here_doc(t_tree *tree, t_vector *fd_in, t_vector *fd_out);
void	close_vector_fd(t_vector *fd);
int		exec_builtin(char **arg);

#endif