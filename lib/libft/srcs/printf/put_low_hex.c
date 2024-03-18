/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_low_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:04:56 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/17 23:26:53 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	put_low_hex(t_vector *v, va_list arg)
{
	char	*str;

	str = ft_itoa_base(va_arg(arg, size_t), "0123456789abcdef");
	if (!str)
		return (-1);
	if (ft_vector_add_n(v, str, ft_strlen(str)) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}
