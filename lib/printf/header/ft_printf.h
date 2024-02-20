/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:57:58 by lrio              #+#    #+#             */
/*   Updated: 2024/01/18 00:18:09 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

typedef struct s_utils
{
	int	*len;
	int	fd;
}		t_utils;

int		fp_printaddress(unsigned long long address, t_utils u);
int		fp_putnbr(int n, t_utils u);
int		fp_putnbr_base(unsigned int nbr, char *base, t_utils u);
int		ft_dprintf(int fd, const char *s, ...);
int		fp_isdigit(int c);
size_t	fp_strlen(char *s);
int		fp_putchar(char c, t_utils u);
int		fp_putstr(char *str, t_utils u);

#endif
