/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:33:49 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/20 23:28:13 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The bzero() function sets the first n bytes of the area starting at s 
 * to zero (bytes containing aq\0aq).
 *@param s: The memory block that you want to set to zero n: Number of bytes 
 *to set to zero
 *@return None
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
