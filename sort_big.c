/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:46:21 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/20 16:23:27 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_all *all)
{
	initial_move_a_to_b(all);
	while (!(is_sorted(all) && all->size_b == 0))
	{
		if (all->size_b >= 1 && all->size_b <= 5)
			sort_five_b_to_a(all);
		else if (all->size_b >= 6)
			move_b_to_a(all);
		if (all->size_b == 0)
		{
			sort_five_a_to_b(all);
			move_a_to_b(all);
		}
	}
}

void	sort_five_b_to_a(t_all *all)
{
	int	flag;
	int	min;
	int	size_b;

	flag = all->stack_a->flag;
	min = all->stack_a->prev->index + 1;
	size_b = all->size_b;
	while (size_b > 3)
	{
		if (all->stack_b->index == min)
		{
			pa(all, 1);
			push_down_a(all);
			min++;
		}
		else
			pa(all, 1);
		size_b--;
	}
	sort_three_b_and_merge(all, flag);
}

void	sort_five_a_to_b(t_all *all)
{
	int	flag;
	int	min;
	int	unsorted_counter;

	flag = all->stack_a->flag;
	min = all->stack_a->prev->index + 1;
	unsorted_counter = unsorted_len(all->stack_a);
	if (unsorted_counter <= 5)
	{
		while (unsorted_counter >= 3)
		{
			if (all->stack_a->index == min)
			{
				push_down_a(all);
				min++;
			}
			else
				pb(all, 1);
			unsorted_counter--;
		}
		sort_three_b_and_merge(all, flag);
	}
}

void	sort_three_b_and_merge(t_all *all, int flag)
{
	sort_three_b(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag == -1)
		{
			pa(all, 1);
			push_down_a(all);
		}
		else
			push_down_a(all);
	}
	while (all->stack_a->flag == flag && flag != -1 && \
		all->stack_a->index + 1 == all->stack_a->prev->index)
		push_down_a(all);
}
