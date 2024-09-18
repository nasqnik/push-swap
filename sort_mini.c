#include "push_swap.h"

void sort_three_a(t_all *all)
{
    int first;
    int second;
    int third;

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
    if (is_sorted(all))
        printf("Sorted");
    free_stack(all); // проверить, нет ли дабл фри
}

void sort_five_a(t_all *all) // проверить на разных инпутах
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
    sort_three_a(all);
	pa(all, 1);
	pa(all, 1);
}

void sort_three_b(t_all *all)
{
    int	first;
	int	second;
	int	third;
	int	i;

	first = all->stack_b->index;
	second = all->stack_b->next->index;
	third = all->stack_b->prev->index;
	i = all->size_b;
	if (second > first && second > third)
		rrb(all, 1);
	else if (first > second && first > third)
		rb(all, 1);
	first = all->stack_b->index;
	second = all->stack_b->next->index;
	if (first > second)
		sb(all, 1);
	while (i-- > 0)
	{
		all->stack_b->flag = -1;
		pa(all, 1);
		ra(all, 1);
	}
}