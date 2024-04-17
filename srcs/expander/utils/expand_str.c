/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:01:16 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 20:01:27 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "expand_utils.h"

int8_t	expand_str(char **str, size_t i, t_env *env, char *error)
{
	set_snegative(str[i]);
	if (-1 == expand_ret(&str[i], env->ret)
		|| -1 == expand_var(&str[i], &env->env))
	{
		free_expand(str, i, error);
		return (-1);
	}
	set_negative(str[i]);
	return (0);
}
