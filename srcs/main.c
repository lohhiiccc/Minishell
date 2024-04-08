/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:46:37 by lrio              #+#    #+#             */
/*   Updated: 2024/04/07 20:00:32 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "minishell.h"
#include "env.h"
#include "ft_printf.h"
#include "ms_signal.h"

int	main(int argc, char **argv, char **env)
{
	t_env		new_env;

	(void)argc;
	(void)argv;
	new_env.ret = 0;
	ms_signal();
	if (!isatty(0) || !isatty(1) || -1 == init_env(env, &new_env.env))
	{
		ft_dprintf(2, "minichel: please use a tty\n");
		return (1);
	}
	while (prompt(&new_env))
		;
	return (127);
}
