/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:12:24 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 17:06:33 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Allocates (with malloc(3)) and returns a new node.
 * The variable 'content' is initialized with the value of the parameter 
 * 'content'.
 * The variable 'next' is initialized to NULL.
 * @param content The content to create the new node with.
 * @return The new node.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*int main()
{
	t_list *node = ft_lstnew("Hello");
	printf("%s\n", (char *)node->content);
	return 0;
}*/
