/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:01:34 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/24 11:27:58 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief The calloc() function allocates memory for an array of nmemb elements
 * of size bytes each and returns a pointer to the allocated memory.
 *@param nmemb: Number of elements
 *@param size: Size of each element
 *@return A pointer to the allocated memory, or NULL if the request fails
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*i;

	if (nmemb == 0 || size == 0)
		i = malloc(0);
	else if ((nmemb * size) / nmemb != size)
		return (NULL);
	else
		i = malloc(nmemb * size);
	if (!i)
		return (NULL);
	if (nmemb != 0 || size != 0)
		ft_bzero(i, nmemb * size);
	return (i);
}

/*int main (void)
{
	int  *pointer = ft_calloc(-5, -5);
	printf("pointer: %p \n", pointer);
	//int  *pointer2 = calloc(-5, -5);
	//printf("pointer: %p \n", pointer2);
}*/