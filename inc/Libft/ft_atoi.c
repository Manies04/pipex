/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:32:31 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/22 17:14:35 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The atoi() function converts the initial portion of the string pointed
 * to by nptr to int.
 *@param nptr: The string to convert to int
 *@return The converted value
*/
int	ft_atoi(const char *nptr)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
		return (0);
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	if ((result * sign) < -2147483648 || (result * sign) > 2147483647)
		return (-1);
	return (result * sign);
}
/*int	main(void)
{
	int	d = ft_atoi("-2147483648");
	printf("Result is: %d\n", d);
	return (0);
}*/