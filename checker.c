/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:53:04 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/20 14:24:11 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void error_checker(t_all *all, char *line)
{
	free(line);
	free_stack(all, 1);
}

static void	execute_command(t_all *all, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(all, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(all, 0);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(all, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(all, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(all, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(all, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(all, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(all, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(all, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(all, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(all, 0);
	else
		error_checker(all, line);
}

static void	checker(t_all *all)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		execute_command(all, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(all))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

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

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc > 1)
	{
		all = malloc(sizeof(t_all));
		if (!all)
			return (1);
		parsing(argv, all);
		checker(all);
		free_stack(all, 0);
	}
	return (0);
}
