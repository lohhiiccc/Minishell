/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:58:03 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 00:38:18 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "stddef.h"


int	parenthese_op(t_vector *vector, size_t *parent, size_t i);
int parenthese_cl(size_t *parent);

#endif