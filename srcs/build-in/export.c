/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:44 by lrio              #+#    #+#             */
/*   Updated: 2024/04/07 23:10:32 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "libft.h"

static void	ft_vector_add_and_null(char *cmd, t_vector *env);
static int	found_sep(char *str, char sep);

int	ft_export(char **cmd, t_vector *env)
{
	size_t	i;
	size_t	j;
	int		n;

	i = 1;
	j = 0;
	while (cmd[i])
	{
		n = found_sep(cmd[i], '=');
		if (n != -1)
		{
			while (j < env->nbr_elem)
			{
				if (!ft_strncmp(cmd[i],
						*(char **)ft_vector_get(env, j), n - 1))
					ft_vector_delete_elem(env, j);
				j++;
			}
			ft_vector_add_and_null(cmd[i], env);
		}
		i++;
	}
	return (0);
}

static void	ft_vector_add_and_null(char *cmd, t_vector *env)
{
	char	*temp;

	temp = ft_strdup(cmd);
	ft_vector_delete_elem(env, env->nbr_elem);
	ft_vector_add_ptr(env, temp);
	ft_vector_add_ptr(env, NULL);

}

static int	found_sep(char *str, char sep)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != sep)
		i++;
	if (str && str[i] == sep)
		return (i);
	return (-1);
}
