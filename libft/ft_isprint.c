/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:09:34 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:23:58 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The isprint() function tests for any printing character, including space (` ').  
The value of the argument must be representable as an unsigned char or the 
value of EOF. The isprint() function returns zero if the character tests false 
and returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
