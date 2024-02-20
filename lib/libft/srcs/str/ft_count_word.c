/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:02:07 by lrio              #+#    #+#             */
/*   Updated: 2024/01/16 16:14:27 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

size_t	ft_count_word(char const *s, char sep)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	i = 0;
	j = 0;
	ft_skip(&i, s, sep, 1);
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == sep)
		{
			j = 0;
			while (s[i + j] == sep)
				j++;
			if (s[i + j])
				count ++;
		}
		i = i + j;
		j = 0;
		i++;
	}
	return (count + 1);
}
