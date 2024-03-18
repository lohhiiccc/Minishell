/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:29:49 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 00:37:12 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H

# include "vector.h"
# include <stdarg.h>

typedef enum e_type
{
	CHAR,
	STR,
	ADD,
	INT,
	UNSIGN,
	UP_HEX,
	LOW_HEX,
	OTHER
}	t_type;

typedef int(*	t_put)(t_vector *v, va_list arg);

int	put_char(t_vector *v, va_list arg);
int	put_str(t_vector *v, va_list arg);
int	put_add(t_vector *v, va_list arg);
int	put_int(t_vector *v, va_list arg);
int	put_unsigned(t_vector *v, va_list arg);
int	put_up_hex(t_vector *v, va_list arg);
int	put_low_hex(t_vector *v, va_list arg);

#endif