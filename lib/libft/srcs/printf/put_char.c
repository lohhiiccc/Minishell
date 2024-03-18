/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:41:44 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/17 23:26:28 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

int	put_char(t_vector *v, va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	if (ft_vector_add(v, &c) == -1)
		return (-1);
	return (0);
}
