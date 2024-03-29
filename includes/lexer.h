/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:58:03 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 00:15:12 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "stddef.h"
# include <stdint.h>

uint8_t	lex_string(t_vector *vector, size_t i);
uint8_t	lex_pipe(t_vector *vector, size_t i);
uint8_t	lex_redirect_in(t_vector *vector, size_t i);
uint8_t	lex_redirect_out(t_vector *vector, size_t i);
uint8_t	lex_operator(t_vector *vector, size_t i);
uint8_t	lex_parenthese_op(t_vector *vector, size_t *parent, size_t i);
uint8_t	lex_parenthese_cl(t_vector *vector, size_t *parent, size_t i);
uint8_t	syntax_check(t_vector *tokens);
int8_t	print_syntax_error(t_vector *tokens);

#endif