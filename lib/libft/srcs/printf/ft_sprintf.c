/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:58:40 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/21 12:03:41 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_utils.h"
#include <stdlib.h>
#include <unistd.h>

static int	find_type(char c)
{
	if (c == 'c')
		return (CHAR);
	else if (c == 's')
		return (STR);
	else if (c == 'p')
		return (ADD);
	else if (c == 'd' || c == 'i')
		return (INT);
	else if (c == 'u')
		return (UNSIGN);
	else if (c == 'X')
		return (UP_HEX);
	else if (c == 'x')
		return (LOW_HEX);
	else if (c == 'S')
		return (STRF);
	else
		return (OTHER);
}

static int	put_in_vector(t_vector *v, va_list arg, char c)
{
	const t_put	tab[] = {
		&put_char,
		&put_str,
		&put_add,
		&put_int,
		&put_unsigned,
		&put_up_hex,
		&put_low_hex,
		&put_strfree
	};
	int			i;

	i = find_type(c);
	if (i != OTHER)
		tab[i](v, arg);
	else if (ft_vector_add(v, &c) == -1)
		return (-1);
	return (0);
}

char	*ft_sprintf(char *str, ...)
{
	va_list		arg;
	t_vector	v;
	int			status;

	va_start(arg, str);
	status = 0;
	if (ft_vector_init(&v, sizeof(char)))
		return (NULL);
	while (*str && status != -1)
	{
		if (*str == '%')
			status = put_in_vector(&v, arg, *++str);
		else
			status = ft_vector_add(&v, str);
		str++;
	}
	if (status == -1)
	{
		free(v.addr);
		return (NULL);
	}
	ft_vector_add(&v, "\0");
	va_end(arg);
	return (v.addr);
}
