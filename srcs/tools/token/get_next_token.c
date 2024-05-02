/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:43:32 by lrio              #+#    #+#             */
/*   Updated: 2024/05/02 04:22:46 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "token.h"
#include "libft.h"
#include "ft_printf.h"

static uint8_t	is_sep(char c);
static int8_t	set_cmd(const char *str, t_token *tkn);
static int8_t	fill_token(char *str, t_token *token,
					t_token_type type, char *s);

//todo : securiser strndup
int8_t	get_next_token(char *str, t_token *tkn)
{
	size_t					i;
	static const t_token	type[] = {{"(", T_PARENTHESE_OP},
	{")", T_PARENTHESE_CL}, {"<<", T_RED_IN}, {"<", T_RED_IN},
	{">>", T_RED_OUT}, {">", T_RED_OUT}, {"||", T_LOGICAL_OP},
	{"&&", T_LOGICAL_OP}, {"|", T_PIPE}, {" ", T_IS_SPACE}, {"\t", T_IS_SPACE}};

	i = 0;
	quote_started(1, 0);
	while (i < 11)
	{
		if (ft_strncmp(type[i].str, str, ft_strlen(type[i].str)) == 0)
		{
			if (fill_token(str, tkn, type[i].type, type[i].str) == -1)
				return (-1);
			return (0);
		}
		i++;
	}
	if (str[0] != 0 && set_cmd(str, tkn) == -1)
		return (-1);
	return (0);
}

static int8_t	set_cmd(const char *str, t_token *tkn)
{
	size_t	i;

	i = 0;
	while (is_sep(str[i]))
		i++;
	if (i == 0 && str[i] && str[i + 1] != '&')
		i++;
	tkn->type = T_CMD;
	tkn->str = ft_strndup(str, i);
	if (NULL == tkn->str)
		return (-1);
	return (0);
}

static int8_t	fill_token(char *str, t_token *token,
					t_token_type type, char *s)
{
	token->type = type;
	token->str = ft_strndup(str, ft_strlen(s));
	if (token->str == NULL)
		return (-1);
	return (0);
}

static uint8_t	is_sep(char c)
{
	if (quote_started(0, c))
		return (1);
	return (c && c != '|' && c != '&' && c != '>' && c != '<'
		&& c != '\t' && c != ' ' && c != '(' && c != ')');
}
