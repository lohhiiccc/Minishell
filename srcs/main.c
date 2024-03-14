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
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	t_vector	*fd_in;
	t_vector	*fd_out;
	t_vector	*new_env;
	// char	*temp;
	// int i = 0;

	(void)argc;
	(void)argv;
	fd_in = malloc(sizeof(t_vector));
	fd_out = malloc(sizeof(t_vector));
	new_env = malloc(sizeof(t_vector));
	ft_vector_init(fd_in, sizeof(int));
	ft_vector_init(fd_out, sizeof(int));
	init_env(env, new_env);
	// temp = ft_vector_get(new_env, i);
	// while (temp)
	// {
	// 	printf("%s\n", temp);
	// 	temp = ft_vector_get(new_env, ++i);
	// }
	while (1)
		exec_args(prompt(new_env), fd_in, fd_out);
	ft_vector_free(fd_in, NULL);
	ft_vector_free(fd_out, NULL);
	free(fd_in);
	free(fd_out);
}
