/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:34 by lrio              #+#    #+#             */
/*   Updated: 2024/03/19 23:51:06 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

static int	found_sep(char *str, char sep)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	if (str[i] && str[i] == sep)
		return (i);
	return (-1);
}

static int	is_variable_name(t_cmd *cmd, char *str)
{
	size_t	i;
	int		n;
	char	**env_i;

	i = 0;
	env_i = ft_vector_get(cmd->env, i);
	while (i < cmd->env->nbr_elem)
	{
		n = found_sep(*env_i, '=');
		if (!ft_strncmp(*env_i, str, n - 1))
			return (i);
		i++;
		env_i = ft_vector_get(cmd->env, i);
	}
	return (-1);
}

int	ft_cd(t_cmd *cmd)
{
	char	*str;
	char	*temp;
	int		n;

	if (cmd->arg[2])
	{
		ft_dprintf(2, "Minichel: cd: too many argument\n");
		return (1);
	}
	if (cmd->arg[1])
	{
		temp = getcwd(NULL, 0);
		if (!temp)
			return (1);
		str = ft_sprintf("%s/%s", temp, cmd->arg[1]);
		free(temp);
		if (!str)
			return (1);
		ft_printf("STR = %s\n", str);
		if (chdir(str) == -1)
		{
			ft_dprintf(2, "Minichel: cd: %s\n", strerror(errno));
			return (1);
		}
		return (0);
	}
	n = is_variable_name(cmd, "HOME");
	str = ft_vector_get(cmd->env, n);
	if (chdir(str + 5) == -1)
	{
		ft_dprintf(2, "Minichel: cd: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}
