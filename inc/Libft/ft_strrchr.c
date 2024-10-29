/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:12:00 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/23 15:57:11 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The strrchr() function locates the last occurrence of c (converted to 
 * a char) in the string pointed to by s. The terminating null character is
 * considered to be part of the string.
 *@param s: The string to search.
 *@param i: The character to search for.
 *@return A pointer to the located character, or NULL if the character does not
 * appear in the string.
*/
char	*ft_strrchr(const char *s, int i)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)i)
			return ((char *)&s[len]);
		len--;
	}
	if (i == '\0')
		return ((char *)s);
	return (NULL);
}

/*int main()
{
	char d = 't';
	d += 258;
	printf("Result: %c\n", d);
}*/