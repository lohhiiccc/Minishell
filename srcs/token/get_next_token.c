/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:43:32 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 03:29:47 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "token.h"
#include "libft.h"

static t_token fill_token(char *str, t_token *token, size_t i, const t_token *type);

t_token	get_next_token(char *str)
{
	t_token					token;
	size_t					i;
	static const t_token	type[] = {{"(", PARENTESE_OP}, \
	{")", PARENTESE_CL}, {"<<", RED_IN}, {"<", RED_IN}, {">>", RED_OUT}, \
	{">", RED_OUT}, {"||", LOGICAL_OP}, {"&&", LOGICAL_OP}, {"|", PIPE}, \
	{"\"", QUOTE}, {"'", QUOTE}, {" ", IS_SPACE}, {"\t", IS_SPACE}};

	i = 0;
	while (i < 13)
	{
		if (0 == ft_strncmp(type[i].str, str, ft_strlen(type[i].str)))
			return (fill_token(str, &token, i, type));
		i++;
	}
	i = 0;
	while (str[i] && str[i] != '|' && str[i] != '&' && str[i] != '>' && \
	str[i] != '>' && str[i] != ' ' && str[i] != '\t' && str[i] != '(' && \
	str[i] != ')' && str[i] != '\'' && str[i] != '"')
		i++;
	if (i == 0 && str[i] && str[i + 1] != '&')
		i++;
	token.type = CHAR;
	token.str = ft_strndup(str, i);
	return (token);
}

static t_token fill_token(char *str, t_token *token, size_t i, const t_token *type)
{
	token->type = type[i].type;
	if (type[i].type == QUOTE)
		token->str = get_quote(str);
	else
		token->str = ft_strndup(str, ft_strlen(type[i].str));
	return (*token);
}
