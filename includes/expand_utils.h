/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:22:32 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 22:22:37 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_UTILS_H
# define EXPAND_UTILS_H
# include <stdint.h>
# include "stddef.h"
# include "env.h"
#include "dirent.h"

size_t	get_envline(char **env, char *var);
uint8_t	is_charset(char c);
int8_t	expand_ret(char **str, uint8_t ret);
int8_t	expand_var(char **str, t_vector *env);
void	set_negative(char *str);
void	set_snegative(char *str);
int8_t	add_var(char *s, size_t *i, t_vector *env, t_vector *vector);
int8_t	expand_str(char **str, size_t i, t_env *env, char *error);
void	*free_expand(char **str, size_t i, char *error);
void	remove_quote(char *s);
int8_t wildcard(char *patern);
char	**get_folder(DIR *directory, struct dirent **dir_data);

#endif