/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:07:09 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/09 00:08:55 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Allocates (with malloc(3)) and returns a substring from the string 
 * 's'. The substring begins at index 'start' and is of maximum size 'len'.
 *@param s: The string from which to create the substring.
 *@param start: The start index of the substring in the string 's'.
 *@param len: The maximum length of the substring.
 *@return The substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s || start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* int main(void)
{
	char *d = ft_substr("tripouille", 100, 1);
	printf("Result is: %s\n", d);
	printf("Tester will say: %d\n", !strcmp(d, "")); 
	free(d);
	return (0);
} */
