/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:31 by lrio              #+#    #+#             */
/*   Updated: 2024/05/01 22:25:42 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"

static int	is_variable_name(t_param *param, char *str);

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
	size_t	len;
	char	**env;

	i = 0;
	env = ft_vector_get(&param->env, i);
	while (env[i])
	{
		len = ft_strclen(str, '=');
		if (str[len - 1] == '=')
			return (-1);
		if (!ft_strncmp(env[i], str, len))
			return (i);
		i++;
	}
	return (-1);
}
