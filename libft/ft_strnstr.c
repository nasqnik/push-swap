/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:29:30 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:05:26 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strnstr() function locates the first occurrence of the null-terminated 
string needle in the string haystack, where not more than len characters 
are searched.  Characters that appear after a `\0' character are not searched.  
Since the strnstr() function is a FreeBSD specific API, it
should only be used when portability is not a concern.

If needle is an empty string, haystack is returned; if needle occurs 
nowhere in haystack, NULL is returned; otherwise a pointer to the first 
character of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0' || !needle)
		return ((char *)haystack);
	if (*haystack == '\0' || !haystack)
		return (NULL);
	needle_len = ft_strlen(needle);
	while (len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
