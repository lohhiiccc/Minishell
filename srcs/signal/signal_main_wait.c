/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_main_wait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:37:54 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/22 22:22:45 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

extern int	g_sig_value;

static void	handle_sig(int sig);

void	ms_signal_main_wait(void)
{
	struct sigaction	sa;

	g_sig_value = 0;
	sa = (struct sigaction){0};
	sa.sa_handler = &handle_sig;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
}

static void	handle_sig(int sig)
{
	g_sig_value = sig;
}
