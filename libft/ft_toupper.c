/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:44:47 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:06:36 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The toupper() function converts a lower-case letter to the corresponding 
upper-case letter.  The argument must be representable as an unsigned 
char or the value of EOF.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
