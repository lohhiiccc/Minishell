/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:01:29 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 17:34:27 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	put_int(t_vector *v, va_list arg)
{
	char	*str;

	str = ft_itoa(va_arg(arg, int));
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
