/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:43:32 by lrio              #+#    #+#             */
/*   Updated: 2024/03/02 07:18:02 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "token.h"
#include "libft.h"

static unsigned char	is_sep(char c);
static int	fill_token(char *str, t_token *token, \
							enum e_token_type type, char *s);
//todo: securiser malloc
int get_next_token(char *str, char prev, t_token *tkn)
{
	size_t					i;
	static const t_token	type[] = {{"(", 0, T_PARENTHESE_OP},
	{")", 0, T_PARENTHESE_CL}, {"<<", 0, T_RED_IN}, {"<", 0, T_RED_IN}, {">>", 0, T_RED_OUT},
	{">", 0,  T_RED_OUT}, {"||", 0, T_LOGICAL_OP}, {"&&", 0, T_LOGICAL_OP}, {"|", 0, T_PIPE},
	{"\"", 0, T_QUOTE}, {"'", 0, T_QUOTE}, {" ", 0, T_IS_SPACE}, {"\t", 0, T_IS_SPACE}};

	i = 0;
	tkn->previous = prev;
	while (i < 13) {
		if (0 == ft_strncmp(type[i].str, str, ft_strlen(type[i].str)))
		{
			if (-1 == fill_token(str, tkn, type[i].type, type[i].str))
				return (-1);//todo:
			return (0);
		}
		i++;
	}
	i = 0;//may enlever les quote de la boucle while
	while (is_sep(str[i]))
		i++;
	if (i == 0 && str[i] && str[i + 1] != '&')
		i++;
	tkn->type = T_CHAR;
	tkn->str = ft_strndup(str, i);
	return (0);
}
//todo: securiser malloc
static int	fill_token(char *str, t_token *token,
							t_token_type type, char *s)
{
	token->type = type;
	if (type == T_QUOTE)
		token->str = get_quote(str);
	else
		token->str = ft_strndup(str, ft_strlen(s));
	if (token->str == NULL)
		return (-1);
	return (0);
}

static unsigned char	is_sep(char c)
{
	 return (c && c != '|' && c != '&' && c != '>' && c != '>'
	 		&& c != ' ' && c != '\t' && c != '(' && c != ')'
			&& c != '\'' && c != '"');
}