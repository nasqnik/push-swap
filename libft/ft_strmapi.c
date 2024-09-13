/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:41:58 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:05:11 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

s: The string on which to iterate.
f: The function to apply to each character.

Return value The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.


Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to collect the
results from the successive applications of f.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*array;
	unsigned int	size;
	unsigned int	i;

	if (!s)
		return (NULL);
	size = (unsigned int) ft_strlen(s);
	array = (char *)malloc((size + 1) * sizeof(char));
	if (!array)
		return (NULL);
	ft_strlcpy(array, s, size + 1);
	i = 0;
	while (i < size)
	{
		array[i] = f(i, array[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
