/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:53:04 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/20 14:24:11 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(char **argv, t_all *all)
{
	char	**arr;
	int		arr_size;

	arr = get_line(argv);
	arr_size = 0;
	while (arr[arr_size])
		arr_size++;
	check_arg(arr);
	check_doubles(arr);
	initialize_struct(all, arr_size);
	fill_stack(arr, all, arr_size);
	free_arr(arr, 0);
}

void	sorting(t_all *all)
{
	if (is_sorted(all) || all->size_a <= 1)
		free_stack(all);
	if (all->size_a <= 3)
		sort_three_a(all, 1);
	else if (all->size_a <= 5)
		sort_five_a(all);
	else
		big_sort(all);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc > 1)
	{
		all = malloc(sizeof(t_all));
		if (!all)
			return (1);
		parsing(argv, all);
		sorting(all);
		free_stack(all);
	}
	return (0);
}
