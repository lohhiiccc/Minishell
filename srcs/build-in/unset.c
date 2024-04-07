/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:31 by lrio              #+#    #+#             */
/*   Updated: 2024/04/06 20:46:47 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"

static int	found_sep(char *str, char sep);
static int	is_variable_name(t_cmd *cmd, char *str);

int	ft_unset(t_cmd *cmd)
{
	size_t	i;
	int		n;

	i = 1;
	while (cmd->arg[i])
	{
		n = is_variable_name(cmd, cmd->arg[i]);
		if (n != -1)
			ft_vector_delete_elem(&cmd->env->env, n);
		i++;
	}
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

static int	is_variable_name(t_cmd *cmd, char *str)
{
	size_t	i;
	int		n;
	char	**env_i;

	i = 0;
	env_i = ft_vector_get(&cmd->env->env, i);
	while (i < cmd->env->env.nbr_elem)
	{
		n = found_sep(*env_i, '=');
		if (!ft_strncmp(*env_i, str, n - 1))
			return (i);
		i++;
		env_i = ft_vector_get(&cmd->env->env, i);
	}
	return (-1);
}
