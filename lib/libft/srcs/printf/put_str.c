/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:47:12 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 00:34:47 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	put_str(t_vector *v, va_list arg)
{
	char	*str;

	str = ft_strdup(va_arg(arg, char *));
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
