/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:59:12 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/23 18:35:55 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expand.h"
#include "ft_printf.h"
#include "libft.h"

static void *ambiguous_redirect(char *s, char **tab);

char *expand_file(char *s, t_env *env)
{
	char	**tab;
	char	*res;
	char	*dup;

	tab = ft_null_alloc(2, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[0] = s;
	dup = ft_strdup(s);
	if (dup == NULL)
	{
		free(tab);
		return (NULL);
	}
	tab = expand_cmd(tab, env);
	if (tab == NULL)
		return (NULL);
	if (tab[1])
		return (ambiguous_redirect(dup, tab));
	res = tab[0];
	free(dup);
	free(tab);
	return (res);
}

static void *ambiguous_redirect(char *s, char **tab)
{
	ft_dprintf(2, "minichell: %S: ambiguous redirect\n", s);
	ft_free_tab(tab);
	return (NULL);
}
