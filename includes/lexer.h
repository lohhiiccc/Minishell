/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:58:03 by lrio              #+#    #+#             */
/*   Updated: 2024/02/28 20:09:28 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "stddef.h"

typedef enum e_token_type
{
	NONE,
	PARENTESE_OP,
	PARENTESE_CL,
	RED_IN,
	RED_OUT,
	PIPE,
	LOGICAL_OP,
	QUOTE,
	IS_SPACE,
	CHAR
}	t_token_type;

typedef struct s_token
{
	char			*str;
	t_token_type	type;
}					t_token;

char		*get_quote(char *str);
void		skip_quote(char *str);
t_token		get_next_token(char *str);
t_vector	*split_token(char *str);
#endif