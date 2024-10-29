/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:06:00 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/09 00:09:01 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	num_palavras;
	int		i;

	num_palavras = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			num_palavras++;
		while (s[i] != c && s[i])
			i++;
	}
	return (num_palavras);
}

/**@brief Allocates (with malloc(3)) and returns an array of strings obtained
 * by splitting 's' using the character 'c' as a delimiter. The array must be
 * ended by a NULL pointer.
 * @param s: The string to split.
 * @param c: The delimiter character.
 * @return The array of new strings resulting from the split.
*/
char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**l;
	int		i;

	i = 0;
	l = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !l)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			l[i++] = ft_substr(s, 0, len);
			s = s + len;
		}
	}
	l[i] = NULL;
	return (l);
}
/* int main(void)
{
	char const *s = "Hello,world";
	char c = ',';
	char **result = ft_split(s, c);
	int	i = 0;

	if (result != NULL)
	{
		while (result[i])
		{
			printf("%s\n", result[i]);
			free(result[i]);
			i++;
		}
	}
	else
	{
		printf("Failed to split the string.\n");
	}
	return (0);
} */