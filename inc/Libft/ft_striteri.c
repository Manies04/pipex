/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:27:06 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 01:55:28 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Applies the function f to each character of the string passed as
 * argument, and passing its index as first argument. Each character is passed
 * by address to f to be modified if necessary.
 * @param s: The string to iterate.
 * @param f: The function to apply to each character.
 * @return None.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*void	ft_increment(unsigned int d, char * ch)
{
	(*ch)++;
}
int main(void)
{
	char	potato[] = "Batata";
	ft_striteri(potato, ft_increment);
	printf("Result is: %s\n", potato);
}*/