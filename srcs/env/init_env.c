/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:30:31 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/25 18:11:03 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "env.h"
#include "libft.h"
#include "vector.h"
#include "build_in.h"
#include "ft_printf.h"

int		inc_shlvl(t_vector *new_env);
char	*update_shlvl(char *shlvl);

int	init_env(char **env, t_vector *new_env)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (ft_vector_init(new_env, sizeof(char *)) == -1)
		return (-1);
	while (env[i])
	{
		temp = ft_strdup(env[i]);
		if (!temp || ft_vector_add_ptr(new_env, temp) == -1)
		{
			while (i > 0)
			{
				free(ft_vector_get(new_env, i));
				i--;
			}
			return (-1);
		}
		i++;
	}
	ft_vector_add_ptr(new_env, NULL);
	return (inc_shlvl(new_env));
}

int	inc_shlvl(t_vector *new_env)
{
	char	*shlvl;
	char	*tab[3];

	tab[0] = NULL;
	tab[2] = NULL;
	shlvl = found_value_of_variable("SHLVL", *new_env);
	if (!shlvl)
	{
		tab[1] = ft_strdup("SHLVL=1");
		ft_export(tab, new_env);
		return (0);
	}
	tab[1] = update_shlvl(shlvl);
	if (!tab[1])
		return (-1);
	ft_export(tab, new_env);
	free(tab[1]);
	return (0);
}

char	*update_shlvl(char *shlvl)
{
	int		temp;
	char	*ret;

	temp = ft_atoi(shlvl);
	temp++;
	if (temp < 0)
		temp = 0;
	if (temp >= 1000)
	{
		ft_dprintf(STDERR_FILENO, "Minichel: warning: shell level (%d) too high,\
resetting to 1\n", temp);
		temp = 1;
	}
	free(shlvl);
	shlvl = ft_itoa(temp);
	if (!shlvl)
		return (NULL);
	ret = ft_strjoin("SHLVL=", shlvl);
	if (!ret)
		return (NULL);
	free(shlvl);
	return (ret);
}
