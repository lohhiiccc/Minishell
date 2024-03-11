/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:08 by lrio              #+#    #+#             */
/*   Updated: 2024/03/08 16:30:44 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include "tree.h"

int	main(int argc, char **argv, char **env)
{
	t_tree *tree;
	(void)argc;
	(void)argv;
//	(void)env;
	tree = prompt(env);
	while(1)
	{
		tree = prompt(env);
		(void)tree;
		//free;
	}
}