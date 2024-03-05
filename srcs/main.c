/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:46:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/05 16:25:06 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tree.h"
#include "exec.h"
#include "libft.h"
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	t_tree	*tree;
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	t_cmd	*cmd3;
	t_vector	*fd_in;
	t_vector	*fd_out;

	fd_in = malloc(sizeof(t_vector));
	fd_out = malloc(sizeof(t_vector));
	ft_vector_init(fd_in, sizeof(int));
	ft_vector_init(fd_out, sizeof(int));
	cmd1 = malloc(sizeof(t_cmd));
	cmd2 = malloc(sizeof(t_cmd));
	cmd3 = malloc(sizeof(t_cmd));
	cmd1->arg = malloc(sizeof(char *) * 2);
	cmd2->arg = malloc(sizeof(char *) * 2);
	cmd3->arg = malloc(sizeof(char *) * 2);
	cmd1->arg[0] = "cat";
	cmd1->arg[1] = NULL;
	cmd1->path = "/bin/cat";
	cmd1->env = envp;
	cmd2->arg[0] = "head";
	cmd2->arg[1] = NULL;
	cmd2->path = "/bin/head";
	cmd2->env = envp;
	cmd3->arg[0] = "tail";
	cmd3->arg[1] = NULL;
	cmd3->path = "/bin/tail";
	cmd3->env = envp;
	tree = ft_join_tree(ft_new_tree(cmd1, CMD), ft_join_tree(ft_new_tree(cmd2, CMD), ft_new_tree(cmd3, CMD), NULL, O_OR), NULL, O_PIPE);
	exec_args(tree, fd_in, fd_out);
	free(cmd1->arg);
	free(cmd1);
	free(cmd2->arg);
	free(cmd2);
	free(cmd3->arg);
	free(cmd3);
	// ft_clean_tree(tree);
>>>>>>> Stashed changes
}