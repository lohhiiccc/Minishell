/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:52:07 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 00:52:58 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	put_str_expand(t_vector *v, va_list arg)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_strdup(va_arg(arg, char *));
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == 127)
			break ;
		if (str[i] < 0)
			str[i] = -str[i];
		i++;
	}
	if (ft_vector_add_n(v, str, i) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}
