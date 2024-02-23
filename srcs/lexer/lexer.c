/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:35:59 by lrio              #+#    #+#             */
/*   Updated: 2024/02/23 18:35:59 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_quote
{
	NONE = 0,
	QUOTE = '\'',
	DOUBLE_QUOTE = '"',
};

enum e_quote is_quote(char c)
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

int	quote_lexer(char *str)
{
	int i;
	enum e_quote last;

	i = 0;
	while (str[i])
	{
		if (NONE != is_quote(str[i]))
		{
			last = is_quote(str[i]);
			i++;
			while (str[i] && last != is_quote(str[i]))
				i++;
			if (!str[i])
				return (0);
		}
		i++;
	}
	return (1);
}

int parent_lexer(char *str)
{
	int i;
	enum e_quote last_quote;
	int parent_start;

	i = 0;
	parent_start = 0;
	while (str[i])
	{
		if (str[i] == '(')
			parent_start = 1;
		if (str[i] == ')')
		{
			if (1 == parent_start)
				parent_start = 0;
			else
				return (0);
		}
		if (NONE != is_quote(str[i]))
		{
			last_quote = is_quote(str[i]);
			while (str[i] && last_quote != is_quote(str[i]))
				i++;
		}
		if (str[i])
			i++;
	}
	return (!parent_start);
}

int lexer(char *str)
{
	if (quote_lexer(str) && parent_lexer(str))
		return (1);
	return (0);
}
