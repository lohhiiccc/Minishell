/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:46:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/12 16:17:43 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "exec.h"
#include "libft.h"
#include "minishell.h"
#include "env.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	t_vector	new_env;

	(void)argc;
	(void)argv;
	if (-1 == init_env(env, &new_env))
	{
		return (1);
	}

	while (prompt(&new_env))
		;
//	while (1)
//		prompt(&new_env);

//	free(fd_in);
//	free(fd_out);
}
