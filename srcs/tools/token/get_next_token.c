/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:43:32 by lrio              #+#    #+#             */
/*   Updated: 2024/03/02 02:41:04 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"

static t_token	fill_token(char *str, t_token *token, size_t *i, \
							const t_token *type);
//todo: securiser malloc
t_token get_next_token(char *str, char prev)
{
	t_token					token;
	size_t					i;
	static const t_token	type[] = {{"(", 0, T_PARENTHESE_OP},
	{")", 0, T_PARENTHESE_CL}, {"<<", 0, T_RED_IN}, {"<", 0, T_RED_IN}, {">>", 0, T_RED_OUT},
	{">", 0,  T_RED_OUT}, {"||", 0, T_LOGICAL_OP}, {"&&", 0, T_LOGICAL_OP}, {"|", 0, T_PIPE},
	{"\"", 0, T_QUOTE}, {"'", 0, T_QUOTE}, {" ", 0, T_IS_SPACE}, {"\t", 0, T_IS_SPACE}};

	i = 0;
	token.previous = prev;
	while (i < 13)
	{
		if (0 == ft_strncmp(type[i].str, str, ft_strlen(type[i].str)))
			return (fill_token(str, &token, &i, type));
		i++;
	}
	i = 0;
	while (str[i] && str[i] != '|' && str[i] != '&' && str[i] != '>'
		&& str[i] != '>' && str[i] != ' ' && str[i] != '\t' && str[i] != '('
		&& str[i] != ')' && str[i] != '\'' && str[i] != '"')
		i++;
	if (i == 0 && str[i] && str[i + 1] != '&')
		i++;
	token.type = T_CHAR;
	token.str = ft_strndup(str, i);
	return (token);
}
//todo: securiser malloc
static t_token	fill_token(char *str, t_token *token, size_t *i,
							const t_token *type)
{
	token->type = type[*i].type;
	if (type[*i].type == T_QUOTE)
		token->str = get_quote(str);
	else
		token->str = ft_strndup(str, ft_strlen(type[*i].str));
	return (*token);
}
