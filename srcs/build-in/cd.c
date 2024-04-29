/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:34 by lrio              #+#    #+#             */
/*   Updated: 2024/04/25 18:02:23 by mjuffard         ###   ########lyon.fr   */
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

static void	change_env(char *old_pwd, t_vector *env);
static char	*create_path(t_cmd *cmd, size_t len_tab, t_param *param);

int	ft_cd(t_cmd *cmd, t_param *param)
{
	char	*str;
	char	*old_pwd;
	size_t	len_tab;

	len_tab = ft_tablen(cmd->arg);
	old_pwd = getcwd(NULL, 0);
	if (NULL == old_pwd)
	{
		ft_dprintf(STDERR_FILENO, "Minichel: cd: %s\n", strerror(errno));
		return (1);
	}
	if (len_tab > 2)
	{
		ft_dprintf(STDERR_FILENO, "Minichel: cd: too many argument\n");
		return (1);
	}
	str = create_path(cmd, len_tab, param);
	if (NULL == str)
		return (1);
	if (chdir(str) == -1)
	{
		free(str);
		ft_dprintf(STDERR_FILENO, "Minichel: cd: %s: %s\n", cmd->arg[1], strerror(errno));
		return (1);
	}
	change_env(old_pwd, &param->env);
	free(str);
	return (0);
}

static char	*create_path(t_cmd *cmd, size_t len_tab, t_param *param)
{
	char	*ret;

	if (2 == len_tab)
	{
		if (!strcmp(cmd->arg[1], "-"))
		{
			ret = found_value_of_variable("OLDPWD", param->env);
			if (!ret)
				ft_dprintf(STDERR_FILENO, "Minichel: cd: OLDPWD not set\n");
			else
				ft_printf("%s\n", ret);
		}
		else if (ft_strchr(cmd->arg[1], '/'))
		{
			ret = ft_strdup(cmd->arg[1]);
			if (NULL == ret)
				ft_dprintf(STDERR_FILENO, "Minichel: cd: %s\n", strerror(errno));
		}
		else
		{
			ret = ft_sprintf("./%s", cmd->arg[1]);
			if (NULL == ret)
				ft_dprintf(STDERR_FILENO, "Minichel: cd: %s\n", strerror(errno));
		}
	}
	else
	{
		ret = found_value_of_variable("HOME", param->env);
		if (!ret)
			ft_dprintf(STDERR_FILENO, "Minichel: cd: HOME not set\n");
	}
	return (ret);
}

static void	change_env(char *old_pwd, t_vector *env)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (NULL == tab)
	{
		ft_dprintf(STDERR_FILENO, "Minichel: cd: problem for change OLDPWD in param\n");
	}
	tab[0] = NULL;
	tab[2] = NULL;
	tab[1] = ft_sprintf("OLDPWD=%s", old_pwd);
	if (NULL == tab[1])
		ft_dprintf(STDERR_FILENO, "Minichel: cd: problem for change OLDPWD in param\n");
	else
		ft_export(tab, env);
	free(tab[1]);
	tab[1] = ft_sprintf("PWD=%s", getcwd(NULL, 0));
	if (NULL == tab[1])
		ft_dprintf(STDERR_FILENO, "Minichel: cd: problem for change PWD in param\n");
	else
		ft_export(tab, env);
	ft_free_tab(tab);
}
