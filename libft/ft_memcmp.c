/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:56:41 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:03:07 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memcmp() function compares byte string s1 against byte string s2.  
Both strings are assumed to be n bytes long.

RETURN VALUES
The memcmp() function returns zero if the two strings are identical, 
otherwise returns the difference between the first two differing bytes 
(treated as unsigned char values, so that `\200' is greater than `\0', 
for example).  Zero-length strings are always identical.  This
behavior is not required by C and portable code should only depend 
on the sign of the returned value.

strncmp() and strcmp() treat a 0 byte as the end of a string, and don't compare 
beyond it to memcmp(), a 0 byte has no special meaning
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
