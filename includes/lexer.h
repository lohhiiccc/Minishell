/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:58:03 by lrio              #+#    #+#             */
/*   Updated: 2024/02/26 15:13:38 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
enum e_type
{
	NONE,
	T_TOKEN,
	T_QUOTE,
	T_PARENT,
	T_OPERATOR,
	T_REDIRECTION
};


void	skip_quote(char *str, int *i);
int ft_parenthese(char c, int parenthese[2]);
#endif