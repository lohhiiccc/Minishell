/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:47:51 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 15:18:35 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"

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

int		get_tokens(char *str, t_vector *vector);
void	free_token(t_vector *vector);
t_token	get_next_token(char *str);
char	*get_quote(char *str);

#endif