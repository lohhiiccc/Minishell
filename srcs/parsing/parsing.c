/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:40:48 by lrio              #+#    #+#             */
/*   Updated: 2024/03/08 23:20:19 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "make_tree.h"
/*
 *
 * (ls || ((cat && rm out) > test)) | grep ls
 *
 * (ls || ((cat && rm out) > test))
 *
 * ((cat && rm out) > test)
 *
 * (cat && rm out)
 *
 */

/*
 *
 * (ls || ((cat && rm out) > test)) | grep ls
 *
 *
 *
 * 					( | )
 * 					/	\
 * 				  / 	 \
 * 				(||)	(grep ls)
 * 				/	\
 * 			  /		 \
 * 			ls		 (>)
 * 					/ 	\
 * 				  / 	 test
 * 			    (&&)
 *  		   /   \
 *  		 /      \
 *  		cat     rm out
 *
 */

/*
 * cat -e > 1 && ls
 *
 * 1: cmd
 *
// *
// */
//
//unsigned char	parsing(t_vector *tokens, t_tree *root)
//{
//
//}
//



/*
 *
 *
 *<<EOF ((ls || make) | (pwd && cat -e) > out)
 *
 *
 *
 *
 */