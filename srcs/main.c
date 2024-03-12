/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:46:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/12 01:08:01 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "exec.h"
#include "libft.h"
#include "minishell.h"
#include "env.h"
#include <stdlib.h>
#include <stdio.h>

// int	main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;
// 	t_tree	*tree;
// 	t_cmd	*cmd1;
// 	t_cmd	*cmd2;
// 	t_cmd	*cmd3;
// 	t_vector	*fd_in;
// 	t_vector	*fd_out;

// 	fd_in = malloc(sizeof(t_vector));
// 	fd_out = malloc(sizeof(t_vector));
// 	ft_vector_init(fd_in, sizeof(int));
// 	ft_vector_init(fd_out, sizeof(int));
// 	cmd1 = malloc(sizeof(t_cmd));
// 	cmd2 = malloc(sizeof(t_cmd));
// 	cmd3 = malloc(sizeof(t_cmd));
// 	cmd1->arg = malloc(sizeof (char *) * 2);
// 	cmd2->arg = malloc(sizeof (char *) * 2);
// 	cmd3->arg = malloc(sizeof (char *) * 2);
// 	cmd1->arg[0] = ft_strdup("cat");
// 	cmd2->arg[0] = ft_strdup("ls");
// 	cmd3->arg[0] = ft_strdup("cat");
// 	cmd1->path = ft_strdup("/bin/cat");
// 	cmd2->path = ft_strdup("/bin/ls");
// 	cmd3->path = ft_strdup("/bin/cat");
// 	cmd1->arg[1] = NULL;
// 	cmd2->arg[1] = NULL;
// 	cmd3->arg[1] = NULL;
// 	cmd1->env = envp;
// 	cmd2->env = envp;
// 	cmd3->env = envp;
// 	tree = ft_join_tree(ft_join_tree(ft_new_tree(cmd1, CMD), ft_new_tree(cmd3, CMD), NULL, O_PIPE), ft_new_tree(cmd2, CMD), NULL, O_PIPE);
// 	exec_args(tree, fd_in, fd_out);
// ft_vector_free(fd_in, NULL);
// ft_vector_free(fd_out, NULL);
// free(fd_in);
// free(fd_out);
// ft_clean_tree(tree);
// }

int	main(int argc, char **argv, char **env)
{
	t_vector	*fd_in;
	t_vector	*fd_out;
	t_vector	*new_env;
	t_env		*test;
	int	i = 0;

	(void)argc;
	(void)argv;
	fd_in = malloc(sizeof(t_vector));
	fd_out = malloc(sizeof(t_vector));
	new_env = malloc(sizeof(t_vector));
	ft_vector_init(fd_in, sizeof(int));
	ft_vector_init(fd_out, sizeof(int));
	init_env(env, new_env);
	test = ft_vector_get(new_env, i);
	while (test)
	{
		printf("%s=%s\n",test->var_name, test->var);
		i++;
		test = ft_vector_get(new_env, i);
	}
	while (1)
		exec_args(prompt(new_env), fd_in, fd_out);
	ft_vector_free(fd_in, NULL);
	ft_vector_free(fd_out, NULL);
	free(fd_in);
	free(fd_out);
}
