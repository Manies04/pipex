/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:35:47 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 01:35:28 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The isalpha() function tests for any character for which isupper() or
 * islower() is true.
 *@param i: The character to test
 *@return Zero if the character tests false and returns non-zero if the
 * character tests true
*/
int	ft_isalpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (1);
	return (0);
}
/* int	main(void)
{
	#include<stdio.h>

	int	result = ft_isalpha('a');
	printf("Result is: %d\n", result);
} */