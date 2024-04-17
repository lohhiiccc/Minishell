/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:40:46 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 17:40:55 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	put_strfree(t_vector *v, va_list arg)
{
	char	*str;
	char	*args;

	args = (va_arg(arg, char *));
	str = ft_strdup(args);
	if (!str)
		return (-1);
	if (ft_vector_add_n(v, str, ft_strlen(str)) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	free(args);
	return (0);
}
