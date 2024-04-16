/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:04:27 by lrio              #+#    #+#             */
/*   Updated: 2024/04/07 21:56:07 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "tree.h"
# include "libft.h"

typedef struct s_fds
{
		t_vector fd_in;
		t_vector fd_out;
}		t_fds;

typedef int(*	t_exec)(t_tree *tree, t_fds *fds);
int		exec_args(t_tree *tree, t_fds *fds, t_tree *root);
int		exec_or(t_tree *tree, t_fds *fds);
int		exec_pipe(t_tree *tree, t_fds *fds);
int		exec_and(t_tree *tree, t_fds *fds);
int		exec_cmd(t_tree *tree, t_fds *fds);
int		exec_input(t_tree *tree, t_fds *fds);
int		exec_output(t_tree *tree, t_fds *fds);
int		exec_apend(t_tree *tree, t_fds *fds);
int		exec_here_doc(t_tree *tree, t_fds *fds);
void	close_vector_fd(t_vector *fd);
int		exec_build_in(t_tree *tree, t_fds *fds);
void	clean_exit(t_tree *tree, t_vector *fd_in, t_vector *fd_out,
				   uint8_t status);
//void	clean_exit(t_tree *tree, t_fds *fds,
//			uint8_t status);
char	*find_path(char *cmd, t_vector *env);
int		is_build_in(char *str);

#endif