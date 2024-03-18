/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:13:14 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 00:34:24 by mjuffard         ###   ########lyon.fr   */
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
		&put_low_hex
	};
	int			i;
	int			ret;

	ret = 0;
	i = find_type(c);
	if (i != OTHER)
		ret = tab[i](v, arg);
	else
		ft_vector_add(v, &c);
	return (ret);
}

int	ft_dprintf(int fd, char *str, ...)
{
	va_list		arg;
	t_vector	*v;
	int			ret;

	va_start(arg, str);
	v = malloc(sizeof(t_vector));
	if (!v)
		return (-1);
	if (ft_vector_init(v, sizeof(char)))
		return (-1);
	while (*str)
	{
		if (*str == '%')
			put_in_vector(v, arg, *++str);
		else
			if (ft_vector_add(v, str) == -1)
				return (-1);
		str++;
	}
	ret = write(fd, v->addr, v->nbr_elem);
	va_end(arg);
	free(v->addr);
	free(v);
	return (ret);
}
