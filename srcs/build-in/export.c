/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:44 by lrio              #+#    #+#             */
/*   Updated: 2024/03/14 19:08:17 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	ft_vector_add_and_null(t_cmd *cmd, size_t i)
{
		char	*temp;

		temp = ft_strdup(cmd->arg[i]);
		ft_vector_delete_elem(cmd->env, cmd->env->nbr_elem);
		ft_vector_add_ptr(cmd->env, temp);
		ft_vector_add_ptr(cmd->env, NULL);

}

static int	found_sep(char *str, char sep)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	if (str[i] == sep)
		return (i);
	return (-1);
}

int	ft_export(t_cmd *cmd)
{
	size_t	i;
	size_t	j;
	int		n;

	i = 1;
	j = 0;
	while (cmd->arg[i])
	{
		n = found_sep(cmd->arg[i], '=');
		if (n != -1)
		{
			while (j < cmd->env->nbr_elem)
			{
				if (!ft_strncmp(cmd->arg[i], *(char **)ft_vector_get \
				(cmd->env, j), n - 1))
					ft_vector_delete_elem(cmd->env, j);
				j++;
			}
			ft_vector_add_and_null(cmd, i);
		}
		i++;
	}
	return (0);
}
