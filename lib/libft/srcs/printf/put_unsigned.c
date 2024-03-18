/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:03:01 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/17 23:30:17 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	put_unsigned(t_vector *v, va_list arg)
{
	char	*str;

	str = ft_itoa(va_arg(arg, unsigned int));
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
