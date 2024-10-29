/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:35:35 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 01:34:36 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The isalnum() function tests for any character for which isalpha() or
 * isdigit() is true.
 *@param i: The character to test
 *@return Zero if the character tests false and returns non-zero if the
 * character tests true
*/
int	ft_isalnum(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')
		|| (i >= '0' && i <= '9'))
		return (1);
	return (0);
}
/* int	main(void)
{
	int	result = ft_isalnum('4');
	printf("Result is: %d\n", result);
} */