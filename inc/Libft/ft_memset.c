/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:36:32 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 01:49:40 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The memset() function fills the first len bytes of the memory area
 * pointed to by str with the constant byte c.
 *@param str: The memory area to fill
 *@param c: The constant byte to fill the memory area with
 *@param len: The number of bytes to fill
 *@return A pointer to the memory area str.
*/
void	*ft_memset(void *str, int c, size_t len)
{
	char	*p;

	p = (char *)str;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (str);
}
