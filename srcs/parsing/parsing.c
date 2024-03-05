/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:40:48 by lrio              #+#    #+#             */
/*   Updated: 2024/03/05 17:17:35 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tree.h"

/*
 *
 * (ls || ((cat && rm out) > test)) | grep ls
 * (ls || ((cat && rm out) > test))
 * ((cat && rm out) > test)
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
 */


//t_tree *parsing(t_vector *tokens)
//{
//
//}
