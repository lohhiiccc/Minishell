/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:13:14 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/21 13:50:47 by mjuffard         ###   ########lyon.fr   */
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
	else if (c == 'e')
		return (STRE);
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
			&put_strfree,
			&put_str_expand
	};
	int			i;

	i = find_type(c);
	if (i != OTHER)
		tab[i](v, arg);
	else if (ft_vector_add(v, &c) == -1)
		return (-1);
	return (0);
}


int	ft_dprintf(int fd, char *str, ...)
{
	va_list		arg;
	t_vector	v;
	int			ret;

	ret = 0;
	va_start(arg, str);
	if (ft_vector_init(&v, sizeof(char)))
		return (-1);
	while (*str && ret != -1)
	{
		if (*str == '%')
			ret = put_in_vector(&v, arg, *++str);
		else
			ret = ft_vector_add(&v, str);
		str++;
	}
	if (ret == -1)
		return (-1);
	ret = write(fd, v.addr, v.nbr_elem);
	va_end(arg);
	free(v.addr);
	return (ret);
}
