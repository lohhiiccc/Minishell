/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:47:51 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 22:23:27 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdint.h>

# include "vector.h"

#define LEXER_ER_QUOTE "syntax error near unexpected token `%c'\n"
#define LEXER_ER_STR "syntax error near unexpected token `%e'\n"
#define LEXER_ER_NEWLINE "syntax error near unexpected token `NewLine'\n"


typedef enum e_token_type
{
	T_NONE,
	T_CMD,
	T_ARG,
	T_PARENTHESE_OP,
	T_PARENTHESE_CL,
	T_RED_IN,
	T_RED_OUT,
	T_PIPE,
	T_LOGICAL_OP,
	T_IS_SPACE,
	T_FILES,
	T_NEWLINE,
}	t_token_type;

typedef struct s_token
{
	char			*str;
	t_token_type	type;
}					t_token;

int8_t	get_tokens(char *str, t_vector *vector);
void	free_token(t_vector *vector);
int8_t	get_next_token(char *str, t_token *tkn);
int8_t	quote_started(unsigned char reset, char c);
void	tag_files(t_vector *tokens);
void	tag_arg(t_vector *tokens);

#endif