/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:30:28 by tiade-al          #+#    #+#             */
/*   Updated: 2024/11/26 23:46:03 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**@brief This function calculates the length of a string.
 *@param str: The string to calculate the length of.
 *@return The number of characters in the string.
*/
size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i + (s[i] == '\n'));
}
//se a string == '\n' ele retorna 1, se não ele retorna 0

/**@brief This function concatenates two strings.
 * @param *str: The first string (What was left behind).
 * @param *buffer: The second string.
 * @return The new string.
*/
char	*ft_strjoin_gnl(char *str, char *buffer)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = (char *)malloc(ft_strlen_gnl(str) + ft_strlen_gnl(buffer) + 1);
	if (!new_str)
		return (0);
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		new_str[i + j] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	new_str[i + j] = '\0';
	free (str);
	return (new_str);
}

/**@brief This function checks if there is a newline in the buffer.
 * @param *buffer: The buffer to check.
 * @param i: The variable to check if there is a newline.
 * @return 1 if there is a newline, 0 if there is not.
*/
int	ft_checknewline_gnl(char *buffer, int i)
{
	char	*bc;
	char	*t;

	bc = buffer;
	t = buffer;
	while (*bc)
	{
		if (*bc == '\n')
		{
			i = 1;
			*bc++ = '\0';
			break ;
		}
		*bc++ = '\0';
	}
	if (i == 1)
	{
		while (*bc)
		{
			*t++ = *bc;
			*bc++ = '\0';
		}
	}
	return (i);
}
