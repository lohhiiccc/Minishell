/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:46:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/18 01:23:47 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"
#include "env.h"

int	main(int argc, char **argv, char **env)
{
	t_vector	new_env;

	if (!isatty(0))
		return (1);
	(void)argc;
	(void)argv;
	if (-1 == init_env(env, &new_env))
		return (1);
	while (prompt(&new_env))
		;
}
