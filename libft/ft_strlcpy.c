/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:51:39 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:04:52 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    - copies size - 1 characters and null-terminates the result;
    - always null-terminates the destination string, as long as the size 
    is greater than 0;
    - desiged to prevent the buffer overflow by esurng the destination string 
    is null-terminated, even if the source sting is too long;
    - returns the total length of the string it tried to create (src string). 
    this allows to detect truncation (compare the size and the strlen(src))
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	count;
	unsigned int	i;

	count = ft_strlen(src);
	if (!dst || !src)
		return (count);
	if (dstsize < 1)
		return (count);
	i = 0;
	while ((src[i] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
