/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:09:37 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:24:54 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The isalpha() function tests for any character for which isupper(3) or 
islower(3) is true.  The value of the argument must be representable as an 
unsigned char or the value of EOF. The isalpha() function returns zero if the 
character tests false and returns non-zero if the character tests
true.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
