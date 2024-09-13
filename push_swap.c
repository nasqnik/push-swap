/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:53:04 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/13 16:59:09 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all *parsing(char **argv)
{
    t_all *all;
    char **arr;

    arr = get_line(argv);
    check_arg(arr);
    check_doubles(arr);
    
}

int main (int argc, char **argv)
{
    t_all *all;
    
    if (argc > 1)
    { all = parsing(argv);
        
    }
}