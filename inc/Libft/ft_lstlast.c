/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:50:14 by tiade-al          #+#    #+#             */
/*   Updated: 2024/05/02 19:11:37 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return The last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/* int main()
{
	t_list *node = ft_lstnew("Hello");
	t_list *node2 = ft_lstnew("World");
	t_list *node3 = ft_lstnew("!");
	t_list *node4 = ft_lstnew("!");
	node->next = node2;
	node2->next = node3;
	node3->next = node4;
	printf("%p\n", ft_lstlast(node)->content);
	return 0;
} */