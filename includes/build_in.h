/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:33:27 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/19 19:03:19 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H
# define BUILD_IN_H

# include "tree.h"

int	ft_echo(t_cmd *cmd);
int	ft_unset(t_cmd *cmd);
int	ft_pwd(void);
int	ft_export(t_cmd *cmd);
int	ft_cd(t_cmd *cmd);
int	ft_env(t_cmd *cmd);
#endif