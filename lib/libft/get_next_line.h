/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:15:22 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/09 03:22:50 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FD_MAX 1024

size_t	ft_nxtln(char *str);
char	*ft_clean(char *str1, char *str2);
void	ft_memmove(char *rest, size_t n);
char	*get_next_line(int fd);
char	*ft_strnjoin(char *str1, char *str2, size_t n);

#endif