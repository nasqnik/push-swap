/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:16:49 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:04:14 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strdup() function allocates sufficient memory for a copy of the 
string s1, does the copy, and returns a pointer to it.  The pointer may 
subsequently be used as an argument to the function free(3).

If insufficient memory is available, NULL is returned and errno is set to ENOMEM.

The strndup() function copies at most n characters from the string s1 always 
NUL terminating the copied string.
*/

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*buffer;

	size = 0;
	size = ft_strlen(s1) + 1;
	buffer = malloc(size * sizeof(char));
	if (!(buffer))
		return (NULL);
	buffer = ft_memcpy(buffer, s1, size);
	return (buffer);
}
