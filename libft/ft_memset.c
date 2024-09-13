/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:27:09 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:03:33 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memset() function writes len bytes of value c (converted to an unsigned 
char)  to the string b. The memset() function returns its first argument.

Memset is a standard library function in C used to fill a block of memory 
with a particular value. It is often used to initialize a memory buffer to 
a known state.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*pointer;

	pointer = (unsigned char *)b;
	value = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		pointer[i] = value;
		i++;
	}
	return (pointer);
}
