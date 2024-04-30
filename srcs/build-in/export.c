/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:44 by lrio              #+#    #+#             */
/*   Updated: 2024/04/30 04:33:48 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"
#include "build_in.h"

static int	ft_vector_add_and_null(char *cmd, t_vector *env);
static int	found_sep(char *str, char sep);
static int	change_env(t_vector *env, char **cmd, int n, size_t i);

int	ft_export(char **cmd, t_vector *env)
{
	size_t	i;
	int		n;

	i = 1;
	while (cmd[i])
	{
		n = found_sep(cmd[i], '=');
		if (n != -1 && change_env(env, cmd, n, i))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_vector_add_and_null(char *cmd, t_vector *env)
{
	char	*temp;

	temp = ft_strdup(cmd);
	ft_vector_delete_elem(env, env->nbr_elem);
	if (ft_vector_add_ptr(env, temp) == -1
		|| ft_vector_add_ptr(env, NULL) == -1)
		return (1);
	return (0);
}

static int	change_env(t_vector *env, char **cmd, int n, size_t i)
{
	size_t	j;
	char	**clean;

	j = 0;
	while (j < env->nbr_elem)
	{
		if (!ft_strncmp(cmd[i], *(char **)ft_vector_get(env, j), n + 1))
		{
			clean = ft_vector_get(env, j);
			free(*clean);
			ft_vector_delete_elem(env, j);
		}
		j++;
	}
	if (ft_vector_add_and_null(cmd[i], env))
		return (1);
	return (0);
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
