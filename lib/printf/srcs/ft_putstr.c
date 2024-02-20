/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:57:24 by lrio              #+#    #+#             */
/*   Updated: 2023/11/17 19:51:24 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	fp_putstr(char *str, t_utils u)
{
	size_t	lenstr;

	if (!str)
	{
		if (-1 == fp_putstr("(null)", u))
			return (-1);
		return (1);
	}
	lenstr = fp_strlen(str);
	if (-1 == write(u.fd, str, lenstr))
		return (-1);
	u.len += lenstr;
	return (1);
}
