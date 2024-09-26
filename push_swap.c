/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:53:04 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/26 18:21:32 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(char **argv, t_all *all)
{
	char	**arr;
	int		arr_size;

	arr = get_line(argv);
	all->size_a = 0;
	all->size_b = 0;
	if (!arr)
		free_stack(all, 1);
	arr_size = 0;
	while (arr[arr_size])
		arr_size++;
	check_arg(arr, all);
	check_doubles(arr, all);
	initialize_struct(all, arr_size);
	fill_stack(arr, all, arr_size);
	free_arr(arr);
}

void	sorting(t_all *all)
{
	if (is_sorted(all) || all->size_a <= 1)
		free_stack(all, 0);
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
		free_stack(all, 0);
	}
	return (0);
}
