/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:46 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:23:42 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Deletes and frees the given node and every successor of that node, 
using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.

lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
