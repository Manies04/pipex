/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:45:21 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 01:39:56 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The isprint() function tests for any printing character, including 
 * space.
 *@param i: The character to test
 *@return Zero if the character tests false and returns non-zero if the
 * character tests true.
*/
int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}
/* int	main(void)
{
	#include<stdio.h>

	int	result = ft_isprint('a');
	printf("Result is: %d\n", result);
} */