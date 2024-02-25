/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/25 14:22:09 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

enum e_quote
{
	NONE = 0,
	QUOTE = '\'',
	DOUBLE_QUOTE = '"',
};

static enum e_quote is_quote(char c)
{
	static const char tab[] = {QUOTE, DOUBLE_QUOTE};
	int i;

	i = 0;
	while (i < 4)
	{
		if (c == tab[i])
			return (tab[i]);
		i++;
	}
	return (NONE);
}

static void	skip_quote(char *str, int *i)
{
	char	start;

	start = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != start)
		(*i)++;
}

int lexer(char *str)
{
	int		i;
	int		parenthese[2];

	ft_memset(parenthese, 0, sizeof(int) * 2);
	i = 0;
	while (str[i])
	{
		if ('(' == str[i])
			parenthese[0]++;
		if (')' == str[i] && parenthese[0] >= parenthese[1] + 1)
		{
			parenthese[1]++;
		}
		else if (')' == str[i])
			return 0;
		if (NONE != is_quote(str[i]))
			skip_quote(str, &i);
		if (!str[i])
			return (0);
		i++;
	}
	if (parenthese[0] != parenthese[1])
		return (0);
	return (1);
}
