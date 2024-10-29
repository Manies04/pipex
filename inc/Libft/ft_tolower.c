/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:47:54 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 02:03:50 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The tolower() function converts an upper-case letter to the 
 * corresponding lower-case letter.
 *@param i: The character to convert.
 *@return The corresponding lower-case letter if i is an upper-case letter.
*/
int	ft_tolower(int i)
{
	if (i >= 'A' && i <= 'Z')
	{
		i += 32;
	}
	return (i);
}
