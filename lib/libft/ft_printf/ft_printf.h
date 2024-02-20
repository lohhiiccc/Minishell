/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:36:47 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 12:06:04 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UPPER_HEX "0123456789ABCDEF"
# define LOWER_HEX "0123456789abcdef"

# include <unistd.h>

int		ft_putnbrbase(unsigned int n, char *base, int *count);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int n, int *count);
int		ft_putunnbr(unsigned int n, int *count);
size_t	ft_strlen(char *str);
int		ft_putaddr(size_t n, char *base, int *count);

#endif