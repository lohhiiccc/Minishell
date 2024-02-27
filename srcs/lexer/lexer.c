/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/27 16:34:52 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "lexer.h"

static int	lexer_ret(char *str, int res);
static char	*format(char *str);

int fast_check(char *str)
{
	int i;
	enum e_str_type value[3];

	i = 0;
	while (str[i] && str[i + 1] && str[i + 2])
	{
		value[0] = get_type(str[i]);
		value[1] = get_type(str[i + 1]);
		value[2] = get_type(str[i + 2]);
		if ((value[0] == T_OPERATOR || value[0] == T_REDIRECTION) && value[0] == value[1] && (value[2] == T_OPERATOR || value[2] == T_REDIRECTION))
			return (1);
		i++;
	}
	return (0);
}

int	lexer(char *str)
{
	int			i;
	int			parenthese[2];
	enum e_str_type	type;
	enum e_str_type last;
	char *lex_str;

	lex_str = format(str);
	if (NULL == lex_str)
		return (0);
	last = NONE;
	ft_memset(parenthese, 0, sizeof(int) * 2);
	i = 0;
	if (fast_check(lex_str))
		return (lexer_ret(lex_str, 0));
	while (lex_str[i])
	{
		type = get_type(lex_str[i]);
		if ((type == T_PARENT && !ft_parenthese(lex_str[i], parenthese)) || (type == T_OPERATOR && lexer_operator(&last, &type, lex_str, &i)) || (type == T_REDIRECTION &&
				lexer_redirection(&last, &type, lex_str, &i)))
			return (lexer_ret(lex_str, 0));
		else if (type == T_QUOTE)
			skip_quote(lex_str, &i);
		if (!lex_str[i])
			return (lexer_ret(lex_str, 0));
		last = type;
		i++;
	}
	if (parenthese[0] != parenthese[1] || last == T_OPERATOR || last == T_REDIRECTION)
		return (lexer_ret(lex_str, 0));
	return (lexer_ret(lex_str, 1));
}

static char	*format(char *str)
{
	int i;
	int j;
	char *res;

	if (ft_strlen(str) == 0)
		return (ft_strdup(str));
	res = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (NULL == res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t'))
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	if (count_str(str, "||") != count_str(res, "||") || count_str(str, "&&") != count_str(res, "&&") ||
			count_str(str, ">>") != count_str(res, ">>") || count_str(str, "<<") != count_str(res, "<<") )
		return (NULL);
	return (res);
}

static int	lexer_ret(char *str, int res)
{
	free(str);
	return (res);
}
