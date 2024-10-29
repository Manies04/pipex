/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:57:14 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/24 12:06:40 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The strlen() function calculates the length of the string s, excluding
 * the terminating null byte ('\0').
 *@param str: The string to calculate the length of.
 *@return The number of characters in the string.
*/
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*int	main(void)
{
	#include<stdio.h>

	int	result = ft_strlen("Batata");
	printf("Result is: %d\n", result);
}*/