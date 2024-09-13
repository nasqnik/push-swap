/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:26:49 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/10 13:03:38 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
c: The character to output.
fd: The file descriptor on which to write.

Outputs the character ’c’ to the given file
descriptor

*/

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
