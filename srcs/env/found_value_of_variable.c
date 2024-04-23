/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_value_of_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:52:58 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 18:02:30 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

static int	found_sep(char *str, char sep);

char	*found_value_of_variable(char *variable_name, t_vector env)
{
	char	*str;
	char	*ret;
	size_t	i;
	int		n;

	i = 0;
	while (i < env.nbr_elem)
	{
		str = *(char **)ft_vector_get(&env, i);
		n = found_sep(str, '=');
		if (!ft_strncmp(variable_name, str, n))
		{
			ret = ft_strdup(str + n + 1);
			return (ret);
		}
		i++;
	}
	return (NULL);
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
