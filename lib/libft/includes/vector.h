/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:38:31 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/07 21:14:25 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>

typedef struct s_vector
{
	void	*addr;
	size_t	nbr_elem;
	size_t	capacity;
	size_t	size;
}	t_vector;

void	ft_vector_free(t_vector *vector, void (*content_free)(void *));
void	*ft_vector_get(t_vector *vector, size_t n);
void	ft_vector_trim(t_vector *vector);
void	ft_vector_delete_elem(t_vector *vector, size_t n);
int		ft_vector_add(t_vector *vector, void *elem);
int		ft_vector_init(t_vector *vector, size_t size);
int		ft_vector_resize(t_vector *vector, size_t new_size);
int		ft_vector_add_ptr(t_vector *vector, void *elem);
void	ft_vector_print_int(void *n);
void	ft_vector_print_str(void *str);
void	ft_vector_print_str_fd(void *str, int fd);
int		ft_vector_iteri(t_vector *vector, void (*f)(void *));
int		ft_vector_iteri_fd(t_vector *vector, void (*f)(void *, int), int fd);
int		ft_vector_add_n(t_vector *vector, void *elem, size_t n);
int		ft_vector_insert(t_vector *vector, void *elem, size_t index, size_t n);

#endif