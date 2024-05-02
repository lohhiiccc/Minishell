/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:31 by lrio              #+#    #+#             */
/*   Updated: 2024/05/02 23:27:17 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tree.h"
#include "libft.h"

static int	is_variable_name(t_param *param, char *str);
static int	ft_strcmp_to_c(char *str1, char *str2, char c);

int	ft_unset(t_cmd *cmd, t_param *param)
{
	size_t	i;
	int		n;

	i = 1;
	while (cmd->arg[i])
	{
		n = is_variable_name(param, cmd->arg[i]);
		if (n != -1)
		{
			free(((char **)param->env.addr)[n]);
			ft_vector_delete_elem(&param->env, n);
		}
		i++;
	}
	return (0);
}

static int	is_variable_name(t_param *param, char *str)
{
	size_t	i;
	char	**env;

	i = 0;
	env = ft_vector_get(&param->env, i);
	while (env[i])
	{
		if (!ft_strcmp_to_c(env[i], str, '='))
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_strcmp_to_c(char *str1, char *str2, char c)
{
	size_t	i;

	i = 0;
	while (str1[i] && str1[i] != c)
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (str2[i] == c)
		return (1);
	return (0);
}
