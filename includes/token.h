/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:47:51 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 00:15:18 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"

typedef enum e_token_type
{
	T_NONE = 0,
	T_CMD = 2,
	T_PARENTHESE_OP = 3,
	T_PARENTHESE_CL = 4,
	T_RED_IN = 5,
	T_RED_OUT = 6,
	T_PIPE = 7,
	T_LOGICAL_OP = 8,
	T_IS_SPACE = 9,
	T_FILES = 10
}	t_token_type;

typedef struct s_token
{
	char			*str;
	t_token_type	type;
}					t_token;

int 	get_tokens(char *str, t_vector *vector);
void	free_token(t_vector *vector);
int 	get_next_token(char *str, t_token *tkn);
int 	quote_started(unsigned char reset, char c);
void	tag_files(t_vector *tokens);

#endif