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
	t_env	new_env;

	new_env.ret = 0;
	(void)argc;
	(void)argv;
	if (!isatty(0) || -1 == init_env(env, &new_env.env))
		return (1);
	while (prompt(&new_env))
		;
}
