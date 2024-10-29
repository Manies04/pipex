/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:26:41 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/22 16:47:49 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Iterates the list ’lst’ and applies the function ’f’ on the content
*of each node. Creates a new list resulting of the successive applications of
*the function ’f’. The ’del’ function is used to delete the content of a node
*if needed.
*@param lst: The address of a pointer to a node.
*@param f: The address of the function used to iterate on the list.
*@param del: The address of the function used to delete the content of a node
*if needed.
*@return The new list. NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, current);
		lst = lst->next;
	}
	return (new_lst);
}
