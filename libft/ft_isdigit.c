/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:31:22 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:24:42 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The isdigit() function tests for a decimal digit character.  
Regardless of locale, this includes the following characters only:

     ``0''         ``1''         ``2''         ``3''         ``4''
     ``5''         ``6''         ``7''         ``8''         ``9''

The isdigit() and isnumber() functions return zero if the character tests 
false and return non-zero if the character tests true.

*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
