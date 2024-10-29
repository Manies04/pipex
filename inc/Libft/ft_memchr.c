/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:30:24 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 01:44:05 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The memchr() function locates the first occurrence of c (converted to 
 * an unsigned char) in string s.
 *@param s: The memory block to search
 *@param ch: The character to search for
 *@param n: The number of bytes to search
 *@return A pointer to the byte located, or NULL if no such byte exists within n
 * bytes.
*/
void	*ft_memchr(const void *s, int ch, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s)[i] == ((unsigned char)ch))
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
