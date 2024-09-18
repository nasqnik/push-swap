/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:35:32 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/18 14:11:07 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_max_med_min_a(t_all *all)
{
    int size;
    int min;
    int max;

    if (all->size_a == 0)
        return;
    size = all->size_a;
    min = all->stack_a->index;
    max = all->stack_a->index;

    while (size-- > 0)
    {
        if (min > all->stack_a->index)
            min = all->stack_a->index;
        if (max < all->stack_a->index)
            max = all->stack_a->index;
        all->stack_a = all->stack_a->next;
    }
    all->min = min;
    all->max = max;
    all->med = (min + max) / 2;
}

void	set_max_med_min_b(t_all *all)
{
    int	size;
	int	min;
	int	max;

	if (all->size_b == 0)
		return ;
	size = all->size_b;
	min = all->stack_b->index;
	max = all->stack_b->index;
	while (size-- > 0)
	{
		if (min > all->stack_b->index)
			min = all->stack_b->index;
		if (max < all->stack_b->index)
			max = all->stack_b->index;
		all->stack_b = all->stack_b->next;
	}
	all->max = max;
	all->med = (min + max) / 2;
}

void move_min_from_b_to_down_a(t_all *all)
{
    while (all->stack_b->prev->flag == -1)
        rrb(all, 1);
    while (all->stack_b->flag == -1)
    {
        pa(all, 1);
        ra(all, 1);
    }
}

void	search_min_a_to_b(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		push_down_a(all);
	}
	else if (all->stack_b->next->index == min)
	{
		sb(all, 1);
		pa(all, 1);
		push_down_a(all);
	}
	else if (all->stack_b->prev->index == min)
	{
		rrb(all, 1);
		pa(all, 1);
		push_down_a(all);
	}
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		push_down_a(all);
	}
}

int	search_min_b_to_a(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		push_down_a(all);
		return (1);
	}
	else if (all->stack_a->index == min)
		push_down_a(all);
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		push_down_a(all);
	}
	return (0);
}