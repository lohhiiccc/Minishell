/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:26 by lrio              #+#    #+#             */
/*   Updated: 2024/03/19 18:57:38 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_pwd(void)
{
	char	*ret;

	ret = getcwd(NULL, 0);
	if (!ret)
		return (1);
	if (printf("%s\n", ret) == -1)
		return (1);
	free(ret);
	return (0);
}
