/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:58:03 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 17:29:52 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "stddef.h"

int	lex_string(t_vector *vector, size_t i);
int	lex_pipe(t_vector *vector, size_t i);
int	lex_redirect_in(t_vector *vector, size_t i);
int	lex_redirect_out(t_vector *vector, size_t i);
int	lex_operator(t_vector *vector, size_t i);
int	lex_parenthese_op(t_vector *vector, size_t *parent, size_t i);
int	lex_parenthese_cl(t_vector *vector, size_t *parent, size_t i);
int	lex_quote(t_vector *vector, size_t i);

#endif