/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:04:27 by lrio              #+#    #+#             */
/*   Updated: 2024/04/25 18:21:35 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "tree.h"
# include "libft.h"

# define ERROR_MSG "Minichel: %s: %s\n"
# define CMD_NOT_FOUND "Minichel: %s: Command not found\n"
# define IS_DIR "Minichel: %s: Is a directory\n"

typedef struct s_fds
{
	t_vector	fd_in;
	t_vector	fd_out;
}		t_fds;

typedef int(*	t_exec)(t_tree *tree, t_fds *fds, t_param *param);
int		exec_args(t_tree *tree, t_fds *fds, t_tree *root, t_param *param);
int		exec_or(t_tree *tree, t_fds *fds, t_param *param);
int		exec_pipe(t_tree *tree, t_fds *fds, t_param *param);
int		exec_and(t_tree *tree, t_fds *fds, t_param *param);
int		exec_cmd(t_tree *tree, t_fds *fds, t_param *param);
int		exec_input(t_tree *tree, t_fds *fds, t_param *param);
int		exec_output(t_tree *tree, t_fds *fds, t_param *param);
int		exec_apend(t_tree *tree, t_fds *fds, t_param *param);
int		exec_here_doc(t_tree *tree, t_fds *fds, t_param *param);
int		exec_build_in(t_tree *tree, t_fds *fds, t_param *param);
void	close_vector_fd(t_vector *fd);
void	clean_exit(t_tree *tree, t_vector *fd_in, t_vector *fd_out,
			uint8_t status);
char	*find_path(char *cmd, t_vector *env);
int		is_build_in(char *str);
int		exec_exe(t_tree *tree, t_fds *fds, t_param *param);

#endif