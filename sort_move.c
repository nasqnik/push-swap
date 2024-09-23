/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:46:21 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/20 16:23:27 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_move_a_to_b(t_all *all)
{
	int	len;

	set_max_med_min_a(all);
	len = all->size_a;
	while (len-- > 0 && (all->size_b < all->max - all->med + 1))
	{
		if (all->stack_a->index <= all->med)
		{
			pb(all, 1);
			if (all->stack_b->index == all->min)
			{
				all->stack_b->flag = -1;
				rb(all, 1);
			}
		}
		else
			ra(all, 1);
	}
	move_min_from_b_to_down_a(all);
}

void	move_min_from_b_to_down_a(t_all *all)
{
	while (all->stack_b->prev->flag == -1)
		rrb(all, 1);
	while (all->stack_b->flag == -1)
	{
		pa(all, 1);
		ra(all, 1);
	}
}

void	move_a_to_b(t_all *all)
{
	int	flag;
	int	min;

	flag = all->stack_a->flag;
	while (all->stack_a->flag == flag && flag != -1)
	{
		min = all->stack_a->prev->index + 1;
		if (all->size_b > 1)
			search_min_a_to_b(all);
		if (all->stack_a->index == min)
			push_down_a(all);
		else
			pb(all, 1);
	}
}

void	move_b_to_a(t_all *all)
{
	int	size_b;

	set_max_med_min_b(all);
	size_b = all->size_b;
	while (size_b-- > 0)
	{
		if (search_min_b_to_a(all))
			continue ;
		if (all->stack_b->index > all->med)
		{
			all->stack_b->flag++;
			pa(all, 1);
		}
		else
		{
			all->stack_b->flag++;
			rb(all, 1);
		}
	}
}
