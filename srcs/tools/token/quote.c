/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:21:54 by lrio              #+#    #+#             */
/*   Updated: 2024/03/03 19:12:39 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int quote_started(unsigned char reset, char c)
{
	static char	lastquote = 0;

	if (reset || c == '\0')
	{
		lastquote = 0;
		return (0);
	}
	if ((c == '\'' || c == '"') && lastquote == 0)
		lastquote = c;
	else if ((c == '\'' || c == '"') && lastquote != 0)
	{
		if (lastquote == c)
		{
			lastquote = 0;
			return (0);
		}
	}
	if (lastquote)
		return (1);
	return (0);
}
