/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:34 by lrio              #+#    #+#             */
/*   Updated: 2024/04/09 07:59:25 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "build_in.h"

static char	*found_value_of_variable(char *variable_name, t_vector env);
static size_t	ft_tab_len(char **tab);

int	ft_cd(t_cmd *cmd)
{
	char	*str;
	char	**tab;
	char	*old_pwd;
	size_t	len_tab;

	len_tab = ft_tab_len(cmd->arg);
	tab = malloc(sizeof(char *) * 3);
	old_pwd = getcwd(NULL, 0);
	tab[0] = NULL;
	tab[2] = NULL;
	if (len_tab > 2)
	{
		ft_dprintf(2, "Minichel: cd: too many argument\n");
		return (1);
	}
	else if (len_tab == 2)
	{
		if (!strcmp(cmd->arg[1], "-"))
		{
			str = found_value_of_variable("OLDPWD", cmd->env->env);
			if (!str)
			{
				ft_dprintf(2, "Minichel: cd: OLDPWD not set\n");
				return (1);
			}
		}
		else if (ft_strchr(cmd->arg[1], '/'))
			str = ft_strdup(cmd->arg[1]);
		else
		{
			str = ft_sprintf("./%s", cmd->arg[1]);
			if (!str)
				return (1);
		}
	}
	else
	{
		str = found_value_of_variable("HOME", cmd->env->env);
		if (!str)
		{
			ft_dprintf(2, "Minichel: cd: HOME not set\n");
		 	return (1);
		}
	}
	if (chdir(str) == -1)
	{
		free(str);
		ft_dprintf(2, "Minichel: cd: %s: %s\n", cmd->arg[1], strerror(errno));
		return (1);
	}
	free(str);
	tab[1] = ft_sprintf("OLDPWD=%s", old_pwd);
	if (!tab[1])
		ft_dprintf(2, "Minichel: cd: problem for change OLDPWD in env\n");
	else
		ft_export(tab, &cmd->env->env);
	free(tab[1]);
	tab[1] = ft_sprintf("PWD=%s", getcwd(NULL, 0));
	if (!tab[1])
		ft_dprintf(2, "Minichel: cd: problem for change PWD in env\n");
	else
		ft_export(tab, &cmd->env->env);
	ft_free_tab(tab);
	return (0);
}

static int	found_sep(char *str, char sep)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != sep)
		i++;
	if (str && str[i] && str[i] == sep)
		return (i);
	return (-1);
}

static char	*found_value_of_variable(char *variable_name, t_vector env)
{
	char	*str;
	char	*ret;
	size_t	i;
	int		n;

	i = 0;
	while (i < env.nbr_elem)
	{
		str = *(char **)ft_vector_get(&env, i);
		n = found_sep(str, '=');
		if (!ft_strncmp(variable_name, str, n))
		{
			ret = ft_strdup(str + n + 1);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

size_t	ft_tab_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
