/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:22:32 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/23 18:33:03 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_UTILS_H
# define EXPAND_UTILS_H

# include <stdint.h>

# include "stddef.h"
# include "env.h"
# include "dirent.h"

# define IS_FOLDER "%S%s/ "
# define IS_NOT_FOLDER "%S%s "

size_t	get_envline(char **env, char *var);
uint8_t	is_charset(char c);
int8_t	add_var(char *s, size_t *i, t_vector *env, t_vector *vector);
void	*free_expand(char **str, size_t i, char *error);
uint8_t	have_wildcard(char *str);

int8_t	wildcard(char *patern, char **wildcard);
uint8_t	is_match(char *str, char *patern, size_t i, size_t j);
char	**get_folder(DIR *directory,
			struct dirent **dir_data, uint8_t include_hidden, uint8_t dir);

uint8_t	remove_quote(char *s);
void	set_negative(char *str);
void	set_snegative(char *str);

int8_t	fill_wildecard(char *patern,
			char **folder, char **str, uint8_t is_folder);
int8_t	expand_str(char **str, size_t i, t_param *param, char *error);
int8_t	expand_ret(char **str, uint8_t ret);
int8_t	expand_var(char **str, t_vector *env);
char	**expand_wildcard(char **cmd);

#endif