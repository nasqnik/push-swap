/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:35:18 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:25:31 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The calloc() function contiguously allocates enough space for count 
objects that are size bytes of memory each and returns a pointer to 
the allocated memory.  The allocated memory is filled with bytes of value zero.
*/

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
