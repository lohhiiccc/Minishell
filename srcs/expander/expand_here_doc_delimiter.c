/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_here_doc_delimiter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:00:45 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 20:00:51 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "expand_utils.h"
#include "libft.h"

size_t	expand_delimiter(char *str)
{
	set_snegative(str);
	set_negative(str);
	return (remove_quote(str));
}
