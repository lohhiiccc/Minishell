/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:37:33 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 02:38:41 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_dprintf(int fd, char *str, ...);
int		ft_printf(char *str, ...);
char	*ft_sprintf(char *str, ...);

#endif