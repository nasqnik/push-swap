/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:06:29 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:05:18 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strcmp() and strncmp() functions lexicographically compare the 
null-terminated strings s1 and s2.

The strncmp() function compares not more than n characters.  Because strncmp() 
is designed for comparing strings rather than binary data, characters that 
appear after a `\0' character are not compared.

This function return values that are as follows −
if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && (i < n))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
