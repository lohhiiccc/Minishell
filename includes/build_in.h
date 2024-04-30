/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:33:27 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/30 02:51:21 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H
# define BUILD_IN_H

# include "tree.h"

# define ERR_CD "Minichel: cd: %s\n"
# define ERR_CD_FAIL "Minichel: cd: %s: %s\n"
# define ERR_CD_TOO_MANY_ARGS "Minichel: cd: too many argument\n"
# define ERR_CD_NO_OLDPWD "Minichel: cd: OLDPWD not set\n"
# define ERR_CD_NO_HOME "Minichel: cd: HOME not set\n"
# define ERR_CD_CHG_OLDPWD "Minichel: cd: problem for change OLDPWD in env\n"
# define ERR_CD_CHG_PWD "Minichel: cd: problem for change PWD in env\n"
# define ERR_PWD "Minichel: pwd: %s\n"
# define ERR_EXP "Minichel: export: %s\n"
# define ERR_ECHO "Minichel: echo: %s\n"
# define ERR_EXIT_TOO_MANY_ARGS "Minichel: exit: too many argument\n"

int		ft_echo(t_cmd *cmd, t_vector *fd_out);
int		ft_unset(t_cmd *cmd, t_param *param);
int		ft_pwd(t_vector *fd_out, t_vector *env);
int		ft_export(char **cmd, t_vector *env);
int		ft_cd(t_cmd *cmd, t_param *param);
int		ft_env(t_param *param, t_vector *fd_out);
void	ft_exit(t_tree *tree, t_vector *fd_in, t_vector *fd_out, t_param *param);

#endif