/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:57:36 by lrio              #+#    #+#             */
/*   Updated: 2024/02/25 17:57:38 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_parenthese(char c, int parenthese[2])
{
	if ('(' == c)
		parenthese[0]++;
	if (')' == c && parenthese[0] >= parenthese[1] + 1)
		parenthese[1]++;
	else if (')' == c)
		return (0);
	return (1);
}
