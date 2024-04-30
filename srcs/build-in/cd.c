/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:34 by lrio              #+#    #+#             */
/*   Updated: 2024/05/01 01:29:13 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"
#include "build_in.h"
#include "env.h"
#include "exec.h"

static void	change_env(char *old_pwd, t_vector *env);
static char	*create_path(t_cmd *cmd, size_t len_tab,
				t_param *param, t_vector *fd_out);
static char	*arg_path(t_cmd *cmd, t_param *param, t_vector *fd_out);
static char	*cd_minus(t_param *param, t_vector *fd_out);

int	ft_cd(t_cmd *cmd, t_param *param, t_vector *fd_out)
{
	char	*str;
	char	*old_pwd;
	size_t	len_tab;

	len_tab = ft_tablen(cmd->arg);
	if (len_tab > 2)
	{
		ft_dprintf(STDERR_FILENO, ERR_CD_TOO_MANY_ARGS);
		return (1);
	}
	str = create_path(cmd, len_tab, param, fd_out);
	if (!str)
		return (1);
	old_pwd = getcwd(NULL, 0);
	if (chdir(str) == -1)
	{
		free(str);
		free(old_pwd);
		ft_dprintf(STDERR_FILENO, ERR_CD_FAIL, cmd->arg[1], strerror(errno));
		return (1);
	}
	change_env(old_pwd, &param->env);
	free(old_pwd);
	free(str);
	return (0);
}

static char	*create_path(t_cmd *cmd, size_t len_tab,
	t_param *param, t_vector *fd_out)
{
	char	*ret;

	if (len_tab == 2)
		ret = arg_path(cmd, param, fd_out);
	else
	{
		ret = found_value_of_variable("HOME", param->env);
		if (!ret)
			ft_dprintf(STDERR_FILENO, ERR_CD_NO_HOME);
	}
	return (ret);
}

static char	*cd_minus(t_param *param, t_vector *fd_out)
{
	char	*ret;

	ret = found_value_of_variable("OLDPWD", param->env);
	if (!ret)
		ft_dprintf(STDERR_FILENO, ERR_CD_NO_OLDPWD);
	else if (fd_out->nbr_elem)
		ft_dprintf(*(int *)ft_vector_get(fd_out, fd_out->nbr_elem - 1),
			"%s\n", ret);
	else
		ft_printf("%s\n", ret);
	return (ret);
}

static char	*arg_path(t_cmd *cmd, t_param *param, t_vector *fd_out)
{
	char	*ret;

	if (!strcmp(cmd->arg[1], "-"))
		ret = cd_minus(param, fd_out);
	else if (ft_strchr(cmd->arg[1], '/'))
	{
		ret = ft_strdup(cmd->arg[1]);
		if (!ret)
			ft_dprintf(STDERR_FILENO, ERR_CD, strerror(errno));
	}
	else
	{
		ret = ft_sprintf("./%s", cmd->arg[1]);
		if (!ret)
			ft_dprintf(STDERR_FILENO, ERR_CD, strerror(errno));
	}
	return (ret);
}

static void	change_env(char *old_pwd, t_vector *env)
{
	char	*tab[3];

	tab[0] = NULL;
	tab[2] = NULL;
	tab[1] = ft_sprintf("OLDPWD=%s", old_pwd);
	if (!old_pwd || !tab[1])
		ft_dprintf(STDERR_FILENO, ERR_CD_CHG_OLDPWD);
	else if (ft_export(tab, env))
		ft_dprintf(STDERR_FILENO, ERR_CD_CHG_OLDPWD);
	free(tab[1]);
	tab[1] = ft_sprintf("PWD=%S", getcwd(NULL, 0));
	if (!tab[1])
		ft_dprintf(STDERR_FILENO, ERR_CD_CHG_PWD);
	else if (ft_export(tab, env))
		ft_dprintf(STDERR_FILENO, ERR_CD_CHG_PWD);
	free(tab[1]);
}
