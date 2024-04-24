/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:14:02 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 20:14:07 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "vector.h"
#include "token.h"
#include "env.h"

int8_t print_syntax_error(t_vector *tokens, t_env *env)
{
	env->ret = 2;
	free_token(tokens);
	write(2, "error\n", 6);
	return (-1);
}
