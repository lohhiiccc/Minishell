/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:43:32 by lrio              #+#    #+#             */
/*   Updated: 2024/03/01 05:21:02 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"

static t_token	fill_token(char *str, t_token *token, size_t i, \
							const t_token *type);

t_token	get_next_token(char *str)
{
	t_token					token;
	size_t					i;
	static const t_token	type[] = {{"(",  T_PARENTESE_OP},
	{")",  T_PARENTESE_CL}, {"<<", T_RED_IN}, {"<", T_RED_IN}, {">>", T_RED_OUT},
	{">",  T_RED_OUT}, {"||", T_LOGICAL_OP}, {"&&", T_LOGICAL_OP}, {"|", T_PIPE},
	{"\"", T_QUOTE}, {"'", T_QUOTE}, {" ", T_IS_SPACE}, {"\t", T_IS_SPACE}};

	i = 0;
	while (i < 13)
	{
		if (0 == ft_strncmp(type[i].str, str, ft_strlen(type[i].str)))
			return (fill_token(str, &token, i, type));
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

static t_token	fill_token(char *str, t_token *token, size_t i,
							const t_token *type)
{
	token->type = type[i].type;
	if (type[i].type == T_QUOTE)
		token->str = get_quote(str);
	else
		token->str = ft_strndup(str, ft_strlen(type[i].str));
	return (*token);
}
