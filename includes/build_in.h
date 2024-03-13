/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:33:27 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/12 18:37:59 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H
# define BUILD_IN_H

#include "tree.h"

int	ft_echo(t_cmd *cmd);
int	ft_unset(t_cmd *cmd);
int	ft_pwd(t_cmd *cmd);
int	ft_export(t_cmd *cmd);
int	ft_exit(t_cmd *cmd);
int	ft_env(t_cmd *cmd);
int	ft_cd(t_cmd *cmd);

#endif