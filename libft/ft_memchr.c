/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:25:03 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:02:57 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memchr() function locates the first occurrence of c (converted to an 
unsigned char) in string s. The memchr() function returns a pointer to the byte 
located, or NULL if no such byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			ch;
	const unsigned char		*str;

	i = 0;
	ch = (unsigned char)c;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
