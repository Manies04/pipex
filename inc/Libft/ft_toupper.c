/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:37:11 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 02:04:05 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The toupper() function converts a lower-case letter to the
 * corresponding upper-case letter.
 *@param i: The character to convert.
 *@return The corresponding upper-case letter if i is a lower-case letter.
*/
int	ft_toupper(int i)
{
	if (i >= 'a' && i <= 'z')
	{
		i -= 32;
	}
	return (i);
}
