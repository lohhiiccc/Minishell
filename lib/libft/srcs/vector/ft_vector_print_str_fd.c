/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_print_str_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:13:21 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/07 21:14:17 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_vector_print_str_fd(void *str, int fd)
{
	if (*(char **)str)
		ft_dprintf(fd, "%s\n", *(char **)str);
}
