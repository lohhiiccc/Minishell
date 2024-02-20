/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:36:40 by mjuffard          #+#    #+#             */
/*   Updated: 2023/11/16 16:15:49 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (ft_strlen(str) < 1)
		return (0);
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			n++;
		i++;
	}
	if (str[i - 1] != c)
		n++;
	return (n);
}

size_t	ft_next_word(char const *str, char c, size_t word)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i] == c)
		i++;
	while (str[i] && n < word)
	{
		if (str[i] == c && str[i - 1] != c)
			n++;
		i++;
	}
	while (str[i] && str[i] == c)
		i++;
	return (i);
}

size_t	ft_strlen_nword(char const *str, char c, size_t word)
{
	size_t	i;
	size_t	n;

	i = ft_next_word(str, c, word);
	n = 0;
	while (str[i + n] != c && str[i + n])
		n++;
	return (n);
}

void	ft_clear(char **tab, size_t i)
{
	while (i != 0)
	{
		i--;
		free(tab[i]);
	}
	free (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	i = 0;
	n = ft_count_words(s, c);
	tab = ft_calloc(n + 1, sizeof(char *));
	if (!tab)
		return (0);
	while (i < n)
	{
		tab[i] = ft_substr(s, ft_next_word(s, c, i), ft_strlen_nword(s, c, i));
		if (!tab[i])
			return (0);
		i++;
	}
	return (tab);
}
