/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:02:31 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 20:02:47 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "expand_utils.h"

static int	searchvar(const char *s1, char *s2);

size_t	get_envline(char **env, char *var)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (searchvar(var, env[i]))
			return (i);
		i++;
	}
	return (i);
}

static int	searchvar(const char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && is_charset(s1[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i] == '=')
		return (1);
	return (0);
}
