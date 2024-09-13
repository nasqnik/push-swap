/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:55:31 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:23:34 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: The node to free.
del: The address of the function used to delete the content.

Takes as a parameter a node and frees the memory of the node’s 
content using the function ’del’ given as a parameter 
and free the node. The memory of ’next’ must not be freed.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
