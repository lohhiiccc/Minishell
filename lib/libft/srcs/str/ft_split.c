/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:13:17 by lrio              #+#    #+#             */
/*   Updated: 2024/05/02 04:25:44 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ischarset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

static char	*split_strdup(char *str, char *charset)
{
	size_t	i;
	size_t	width;
	char	*cpy;

	i = 0;
	width = 0;
	while (str[width] != '\0')
		width++;
	cpy = malloc(sizeof(char) * (width + 1));
	if (!cpy)
		return (NULL);
	while (str[i] != '\0' && !ischarset(charset, str[i]))
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static size_t	count_world(char *str, char *charset)
{
	size_t	i;
	size_t	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (ischarset(charset, str[i]) == 0 && \
			ischarset(charset, str[i + 1]))
			c++;
		i++;
	}
	return (c);
}

static void	*free_split(char **tab, size_t i)
{
	while (i)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	size_t	nb_world;
	size_t	i;
	size_t	start;
	char	**res;

	nb_world = count_world(str, charset);
	res = malloc(sizeof(char *) * (nb_world + 1));
	if (!res)
		return (NULL);
	i = 0;
	start = 0;
	while (nb_world != 0)
	{
		while (ischarset(charset, str[start]))
			start++;
		res[i] = split_strdup(&str[start], charset);
		if (!res[i])
			free_split(res, i);
		while (!ischarset(charset, str[start]) && str[start] != '\0')
			start++;
		nb_world--;
		i++;
	}
	res[i] = NULL;
	return (res);
}
