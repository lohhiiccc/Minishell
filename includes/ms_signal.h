/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:22:26 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/19 00:10:37 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNAL_H
# define MS_SIGNAL_H

extern int	g_sig_value;

void	ms_signal_main(void);
void	ms_signal_child(void);
void	ms_signal_main_wait(void);
int		do_nothing(void);

#endif