/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:23:40 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 22:23:41 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "env.h"

char	**expand_cmd(char **cmd, t_env *env);
char	*expand_file(char *s, t_env *env);
size_t	expand_delimiter(char *str);

#endif
