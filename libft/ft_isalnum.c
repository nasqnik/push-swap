/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:42:58 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:25:43 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isalnum() function tests for any character for which isalpha(3) 
or isdigit(3) is true.  The value of the argument must be representable as 
an unsigned char or the value of EOF. The isalnum() function returns zero if the 
character tests false and returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
