/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:13:17 by lrio              #+#    #+#             */
/*   Updated: 2024/03/17 16:25:24 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_skip(size_t *a, const char *s, char c, int include)
{
	size_t	i;

	i = *a;
	if (include == 1)
		while (s[i] && s[i] == c)
			i++;
	else
		while (s[i] && s[i] != c)
			i++;
	*a = i;
}

static void	*ft_free_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	count_word;

	i = 0;
	count_word = ft_count_word(s, c);
	tab = ft_calloc(count_word + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	start = 0;
	ft_skip(&start, s, c, 1);
	while (count_word-- != 0)
	{
		end = start;
		ft_skip(&end, s, c, 0);
		tab[i] = ft_substr(s, start, end - start);
		if (!tab[i])
			return (ft_free_split(tab));
		i++;
		start = end;
		ft_skip(&start, s, c, 1);
	}
	return (tab);
}
