/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:22:09 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/19 01:08:35 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <readline/readline.h>

int	g_sig_value;

static void	handle_sigint(int sig);

void	ms_signal_main(void)
{
	struct sigaction	sa;

	g_sig_value = 0;
	sa = (struct sigaction){0};
	sa.sa_handler = &handle_sigint;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

static void	handle_sigint(int sig)
{
	rl_done = 1;
	g_sig_value = sig;
}
