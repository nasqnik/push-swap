/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:41:14 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:04:45 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Strlcat() appends string src to the end of dst.  It will append at most 
dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, 
unless dstsize is 0 or the original dst string was longer than dstsize 
(in practice this should not happen as it means that either dstsize is 
incorrect or that dst is not a proper string).

return values:
- the total length of the string it tried to create, which is the 
initial length of dst + the length of src;
- if size <= to the length of dst, it returns size + length of src
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dst_len;
	unsigned int	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	j = dst_len;
	i = 0;
	if (dstsize > 0 && dst_len < dstsize - 1)
	{
		while (src[i] && (dst_len + i < dstsize - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (dst_len + src_len);
}
