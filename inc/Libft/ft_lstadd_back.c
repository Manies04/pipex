/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:02:46 by tiade-al          #+#    #+#             */
/*   Updated: 2024/05/15 13:20:56 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Adds the node 'new' at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @return None.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/* int main(void)
{
    t_list *my_list = NULL;
    t_list *new_node1 = ft_lstnew("Node 1 data");
    t_list *new_node2 = ft_lstnew("Node 2 data");

    // Add nodes to the list
    ft_lstadd_back(&my_list, new_node1);
    ft_lstadd_back(&my_list, new_node2);

    // Verify the list
    t_list *current = my_list;
    while (current)
    {
        printf("Node data: %s\n", (char *)current->content);
        current = current->next;
    }

    // Don't forget to free the memory allocated for the list!

    return 0;
} */