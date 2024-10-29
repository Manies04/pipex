/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:06:42 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 02:01:10 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The strnstr() function locates the first occurrence of the 
 * null-terminated
 *@param haystack: The string to search in.
 *@param needle: The string to search for.
 *@param n: The number of characters to search.
 *@return A pointer to the located character, or NULL if the character does not
 * appear in the string.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle == NULL || needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < n)
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < n)
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
/*int main(void)
{
	char *d = ft_strnstr("As batatas sao boas", "batatas", 10);
	printf("Result is: %s\n", d);

	return(0);
}*/