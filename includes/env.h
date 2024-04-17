/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:26:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 22:21:50 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdint.h>
# include "vector.h"

typedef struct s_env
{
	t_vector	env;
	uint8_t		ret;
	int			ptree;
}	t_env;

int		init_env(char **env, t_vector *new_env);
void	clear_env(t_vector *env);
char	*found_value_of_variable(char *variable_name, t_vector env);

#endif