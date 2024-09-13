/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:13:08 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:04:57 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strlen() function computes the length of the string s. The strnlen() 
function attempts to compute the length of s, but never scans beyond the first 
maxlen bytes of s.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
