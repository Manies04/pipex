/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:28:49 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 01:57:34 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The strlcpy() function copies up to size - 1 characters from the 
 * NUL-terminated string src to dst, NUL-terminating the result.
 *@param dst: The destination string.
 *@param src: The source string.
 *@param size: The size of the destination buffer.
 *@return The total length of the string it tried to create.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		i = ft_strlen(src);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
// int main(void)
// {
// 	char *dest;
// 	size_t output;
// 	output = ft_strlcpy(dest, "Cenoura", 8);
// 	ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// 	return(0);
// }