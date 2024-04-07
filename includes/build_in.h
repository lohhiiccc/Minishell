/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:33:27 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/07 22:59:30 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H
# define BUILD_IN_H

# include "tree.h"

int		ft_echo(t_cmd *cmd, t_vector *fd_out);
int		ft_unset(t_cmd *cmd);
int		ft_pwd(t_vector *fd_out);
int		ft_export(char **cmd, t_vector *env);
int		ft_cd(t_cmd *cmd);
int		ft_env(t_cmd *cmd, t_vector *fd_out);
void	ft_exit(t_tree *tree, t_vector *fd_in, t_vector *fd_out);

#endif