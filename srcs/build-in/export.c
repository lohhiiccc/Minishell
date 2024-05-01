/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:44 by lrio              #+#    #+#             */
/*   Updated: 2024/05/01 22:19:07 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"
#include "build_in.h"

static int	ft_vector_add_and_null(char *cmd, t_vector *env);
static int	found_sep(char *str, char sep);
static int	change_env(t_vector *env, char *cmd, int n);
static int	check_variable_name(char *str, int n);

int	ft_export(char **cmd, t_vector *env)
{
	size_t	i;
	int		n;
	int		ret;
	bool	p_error;

	p_error = 0;
	ret = 1;
	i = 0;
	if (!cmd[1])
		return (0);
	while (cmd[++i])
	{
		n = found_sep(cmd[i], '=');
		if (n != -1)
		{
			if (!change_env(env, cmd[i], n))
				ret = 0;
		}
		else if (p_error == 0)
		{
			ft_dprintf(STDERR_FILENO, USE_EQ);
			p_error = 1;
		}
	}
	return (ret);
}

static int	ft_vector_add_and_null(char *cmd, t_vector *env)
{
	char	*temp;

	temp = ft_strdup(cmd);
	if (!temp)
		return (1);
	ft_vector_delete_elem(env, env->nbr_elem - 1);
	if (ft_vector_add_ptr(env, temp) == -1
		|| ft_vector_add_ptr(env, NULL) == -1)
		return (1);
	return (0);
}

static int	check_variable_name(char *str, int n)
{
	size_t	i;

	i = 0;
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
	{
		ft_dprintf(STDERR_FILENO, ERR_EXP_ID, str);
		return (1);
	}
	while (i < (size_t)n)
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
		{
			ft_dprintf(STDERR_FILENO, ERR_EXP_ID, str);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	change_env(t_vector *env, char *cmd, int n)
{
	size_t	i;
	char	**clean;

	i = 0;
	if (check_variable_name(cmd, n))
		return (1);
	while (i < env->nbr_elem)
	{
		if (!ft_strncmp(cmd, *(char **)ft_vector_get(env, i), n + 1))
		{
			clean = ft_vector_get(env, i);
			free(*clean);
			ft_vector_delete_elem(env, i);
		}
		i++;
	}
	if (ft_vector_add_and_null(cmd, env))
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
