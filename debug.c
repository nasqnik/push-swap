#include "push_swap.h"

void debug_a_b_before(t_all *all)
{
    t_node *cursor = all->stack_a;
    printf("\nStack a before: ");
    for (int i = 0; i < all->size_a; i++)
    {
        printf("%d ", cursor->index);
        cursor = cursor->next;
    }    
    
    cursor = all->stack_b;
    printf("\nStack b before: ");
    for (int i = 0; i < all->size_b; i++)
    {
        printf("%d ", cursor->index);
        cursor = cursor->next;
    }
}

void debug_a_b_after(t_all *all)
{
    t_node *cursor = all->stack_a;
    printf("\nStack a after: ");
    for (int i = 0; i < all->size_a; i++)
    {
        printf("%d ", cursor->index);
        cursor = cursor->next;
    }    
    
    cursor = all->stack_b;
    printf("\nStack b after: ");
    for (int i = 0; i < all->size_b; i++)
    {
        printf("%d ", cursor->index);
        cursor = cursor->next;
    }
}