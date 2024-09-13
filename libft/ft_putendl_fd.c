/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:38:10 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:03:42 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string to output.
fd: The file descriptor on which to write.
Outputs the string ’s’ to the given file descriptor
followed by a newline
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
