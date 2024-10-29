/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:15:37 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/22 11:42:28 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Takes as a parameter a node and frees the memory of the node's
 * content using the function 'del' given as a parameter and free the node.
 * The memory of 'next' must not be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 * @return None.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
