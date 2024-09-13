/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:12:52 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:06:27 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The tolower() function converts an upper-case letter to the 
corresponding lower-case letter.  The argument must be representable 
as an unsigned char or the value of EOF. If the argument is an 
upper-case letter, the tolower() function returns the corresponding 
lower-case letter if there is one; otherwise, the argument is returned unchanged.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
