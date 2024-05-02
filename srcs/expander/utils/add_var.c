/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:10:56 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 04:26:29 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "expand_utils.h"
#include "libft.h"

static int8_t	get_value(char *s, size_t i, char **env, t_vector *vector);
static void		keep_quote(char *value);

int8_t	add_var(char *s, size_t *i, t_vector *env, t_vector *vector)
{
	if (get_value(s, *i + 1, ft_vector_get(env, 0), vector) == -1)
		return (-1);
	++*i;
	while (s[*i] && is_charset(s[*i]))
		++*i;
	return (0);
}

static int8_t	get_value(char *s, size_t i, char **env, t_vector *vector)
{
	char	*value;
	char	*str;
	size_t	backup;
	int8_t	ret;

	backup = i;
	str = env[get_envline(env, s + i)];
	value = ft_strdup(str);
	while (s[i] && is_charset(s[i]))
		i++;
	--i;
	if (str == NULL)
	{
		free(str);
		return (0);
	}
	str = value;
	if (!value)
		return (-1);
	value += (i - backup + 2);
	keep_quote(value);
	ret = ft_vector_add_n(vector, value, ft_strlen(value));
	free(str);
	return (ret);
}

static void	keep_quote(char *value)
{
	size_t	i;

	i = 0;
	while (value[i])
	{
		if (value[i] == '\'' || value[i] == '"')
		{
			value[i] = -value[i];
		}
		i++;
	}
}
