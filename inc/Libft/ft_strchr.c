/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:51:36 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/24 10:50:16 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The strchr() function locates the first occurrence of i (converted to
 *  a char) in the string pointed to by s. The terminating null character is
 * considered to be part of the string.
 *@param s: The string to search.
 *@param i: The character to search for.
 *@return A pointer to the located character, or NULL if the character does not
 * appear in the string.
*/
char	*ft_strchr(const char *s, int i)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == (char)i)
			return ((char *)(s + a));
		a++;
	}
	if (i == '\0')
		return ((char *)(s + a));
	return (NULL);
}
