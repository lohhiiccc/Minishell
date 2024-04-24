/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:34 by lrio              #+#    #+#             */
/*   Updated: 2024/04/24 22:05:24 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"
#include "build_in.h"
#include "env.h"
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

static void	change_env(char *old_pwd, t_vector *env);
static char	*create_path(t_cmd *cmd, size_t len_tab, t_env *env);

int	ft_cd(t_cmd *cmd, t_env *env)
{
	char	*str;
	char	*old_pwd;
	size_t	len_tab;

	len_tab = ft_tab_len(cmd->arg);
	old_pwd = getcwd(NULL, 0);
	if (len_tab > 2)
	{
		ft_dprintf(2, "Minichel: cd: too many argument\n");
		return (1);
	}
	str = create_path(cmd, len_tab, env);
	if (!str)
		return (1);
	if (chdir(str) == -1)
	{
		free(str);
		ft_dprintf(2, "Minichel: cd: %s: %s\n", cmd->arg[1], strerror(errno));
		return (1);
	}
	change_env(old_pwd, &env->env);
	free(str);
	return (0);
}

static char	*create_path(t_cmd *cmd, size_t len_tab, t_env *env)
{
	char	*ret;

	if (len_tab == 2)
	{
		if (!strcmp(cmd->arg[1], "-"))
		{
			ret = found_value_of_variable("OLDPWD", env->env);
			if (!ret)
				ft_dprintf(2, "Minichel: cd: OLDPWD not set\n");
			else
				ft_printf("%s\n", ret);
		}
		else if (ft_strchr(cmd->arg[1], '/'))
			ret = ft_strdup(cmd->arg[1]);
		else
			ret = ft_sprintf("./%s", cmd->arg[1]);
	}
	else
	{
		ret = found_value_of_variable("HOME", env->env);
		if (!ret)
			ft_dprintf(2, "Minichel: cd: HOME not set\n");
	}
	return (ret);
}

static void	change_env(char *old_pwd, t_vector *env)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	tab[0] = NULL;
	tab[2] = NULL;
	tab[1] = ft_sprintf("OLDPWD=%s", old_pwd);
	if (!tab[1])
		ft_dprintf(2, "Minichel: cd: problem for change OLDPWD in env\n");
	else
		ft_export(tab, env);
	free(tab[1]);
	tab[1] = ft_sprintf("PWD=%s", getcwd(NULL, 0));
	if (!tab[1])
		ft_dprintf(2, "Minichel: cd: problem for change PWD in env\n");
	else
		ft_export(tab, env);
	ft_free_tab(tab);
}
