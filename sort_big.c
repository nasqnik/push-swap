/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:09:18 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/18 14:09:33 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// 1) first_move = находим медиану в стеке а и перебрасываем в стек б все, что меньше медианы.
//      в стеке б окажется самое минимальное число, которое мы прячем в самый низ стека б. 
//      (дальше) отсортированные числа будут скапливаться внизу стека а. поэтому у мин числа, перемещенного в стек а
//      мы поменяем флаг на -1 (что оно отсортировано). и min_a++. любое отсортированое число получает флаг -1 

void big_sort(t_all *all)
{
    initial_move_a_to_b(all);
    while (!(is_sorted(all) && all->size_b == 0))
    {
        if (all->size_b > 0 && all->size_b < 6)
            sort_five_b_to_a(all);
        else if (all->size_b >= 6)
            move_b_to_a(all);
        if (all->size_b == 0)
        {
            sort_five_a_to_b(all);
            move_a_to_b(all);
        }
    }
        if (is_sorted(all))
        printf("Sorted");
}

void sort_five_a_to_b(t_all *all)
{
    int min;
    int flag;
    int len;

    min = all->stack_a->prev->index + 1;
    flag = all->stack_a->flag;
    len = unsorted_len(all->stack_a);

    if (len <= 5)
    {
        while (len > 2)
        {
            if (all->stack_a->index == min)
            {
                push_down_a(all);
                min++;
            }
            else
                pb(all, 1);
            len--;
        }
        sort_five_a_to_b_continue(all, flag);
    }
}

void sort_five_a_to_b_continue(t_all *all, int flag)
{
    sort_three_a_to_b(all);
    if (all->stack_a->index > all->stack_a->next->index && \
        all->stack_a->flag == all->stack_a->next->flag)
        sa(all, 1);
    while (all->size_b != 0)
    {
        if (all->stack_a->index > all->stack_b->index || \
            all->stack_a->flag != flag)
        {
            pa(all, 1);
            push_down_a(all);
        }
        else
            push_down_a(all);
        while (all->stack_a->flag == flag && flag != -1)
            push_down_a(all);    
    }
}


void sort_five_b_to_a(t_all *all)
{
    int len;
    int min;
    int flag;
    t_node *tmp;
    
    len = all->size_b;
    min = all->stack_a->prev->index + 1;
    flag = all->stack_a->flag;
    tmp = all->stack_a;
    while (len > 3)
    {
        if (all->stack_b->index == min)
        {
            pa(all, 1);
            push_down_a(all);
            min++;
        }
        else
            pa(all, 1);
        len--;
    }
    sort_five_b_to_a_continue(all, flag);
}

void sort_five_b_to_a_continue(t_all *all, int flag)
{
    sort_three_a_to_b(all);
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
			all->stack_a->index +1 == all->stack_a->prev->index)
		push_down_a(all);
}

void	push_down_a(t_all *all)
{
	all->stack_a->flag = -1;
	ra(all, 1);
}