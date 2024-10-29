/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:35:24 by tiade-al          #+#    #+#             */
/*   Updated: 2024/05/02 22:14:57 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/* int main()
{
	t_list *node1 = ft_lstnew("Batata");
	t_list *node2 = ft_lstnew("Batata");
	t_list *node3 = ft_lstnew("Batata");
	t_list *node4 = ft_lstnew("Batata");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	int	result = ft_lstsize(node1);
	printf("Result is: %d\n", result);
} */