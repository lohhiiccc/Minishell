/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:08 by lrio              #+#    #+#             */
/*   Updated: 2024/03/08 14:58:08 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include "tree.h"
#include "exec.h"
#include "libft.h"
#include <stdlib.h>

int	main(int argc, char **argv, char **env)
{
	t_tree *tree;
	(void)argc;
	(void)argv;
	(void)env;
	tree = prompt();
	while(1)
	{
		tree = prompt();
		(void)tree;
		//free;
	}
}