/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:58:03 by lrio              #+#    #+#             */
/*   Updated: 2024/03/03 22:39:33 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "stddef.h"

unsigned char	lex_string(t_vector *vector, size_t i);
unsigned char	lex_pipe(t_vector *vector, size_t i);
unsigned char	lex_redirect_in(t_vector *vector, size_t i);
unsigned char	lex_redirect_out(t_vector *vector, size_t i);
unsigned char	lex_operator(t_vector *vector, size_t i);
unsigned char	lex_parenthese_op(t_vector *vector, size_t *parent, size_t i);
unsigned char	lex_parenthese_cl(t_vector *vector, size_t *parent, size_t i);
unsigned char	lex_quote(t_vector *vector, size_t i);
unsigned char	syntax_check(t_vector *tokens);

#endif