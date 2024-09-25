/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:46:21 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/20 16:23:27 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_all *all, int flag)
{
	int	first;
	int	second;
	int	third;

	first = all->stack_a->index;
	second = all->stack_a->next->index;
	third = all->stack_a->prev->index;
	if (second > first && second > third)
		rra(all, 1);
	else if (first > second && first > third)
		ra(all, 1);
	first = all->stack_a->index;
	second = all->stack_a->next->index;
	if (first > second)
		sa(all, 1);
	if (flag == 1)
		free_stack(all, 0);
}

void	sort_five_a(t_all *all)
{
	while (all->size_a > 3)
	{
		if (all->stack_a->index == 1 || all->stack_a->index == 2)
			pb(all, 1);
		else
			ra(all, 1);
	}
	if (all->stack_b->index < all->stack_b->next->index)
		sb(all, 1);
	sort_three_a(all, 0);
	pa(all, 1);
	pa(all, 1);
	if (all->stack_a->index > all->stack_a->next->index)
		sa(all, 1);
	free_stack(all, 0);
}

void	sort_three_b(t_all *all)
{
	int	first;
	int	second;
	int	third;

	if (all->size_b == 0)
		return ;
	first = all->stack_b->index;
	second = all->stack_b->next->index;
	third = all->stack_b->prev->index;
	if (second > first && second > third)
		rrb(all, 1);
	else if (first > second && first > third)
		rb(all, 1);
	first = all->stack_b->index;
	second = all->stack_b->next->index;
	if (first > second)
		sb(all, 1);
}
