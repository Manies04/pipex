/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:36:02 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 01:37:10 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The isascii() function tests for an ASCII character.
 *@param i: The character to test
 *@return Zero if the character tests false and returns non-zero if the
 * character tests true.
*/
int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (0);
}
/* int	main(void)
{
	#include<stdio.h>

	int	result = ft_isascii('a');
	printf("Result is: %d\n", result);
} */