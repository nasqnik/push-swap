/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:46:21 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/20 16:23:27 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int num, int rank)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->flag = 0;
	node->index = rank;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	lstadd_back_doubly(t_node **stack_a, t_node *node)
{
	t_node	*start;

	if (node == NULL)
		return ;
	start = *stack_a;
	if (start)
	{
		if (start->prev)
		{
			start->prev->next = node;
			node->prev = start->prev;
			node->next = start;
			start->prev = node;
		}
		else
		{
			start->prev = node;
			start->next = node;
			node->prev = start;
			node->next = start;
		}
	}
	else
		*stack_a = node;
}

void	free_stack(t_all *all, int flag)
{
	t_node	*tmp;

	while (all->size_a--)
	{
		tmp = all->stack_a->next;
		free(all->stack_a);
		all->stack_a = NULL;
		all->stack_a = tmp;
	}
	while (all->size_b--)
	{
		tmp = all->stack_b->next;
		free(all->stack_b);
		all->stack_b = NULL;
		all->stack_b = tmp;
	}
	free(all);
	if (flag)
		error();
	exit(EXIT_SUCCESS);
}

int	is_sorted(t_all *all)
{
	int		i;
	t_node	*cursor;

	cursor = all->stack_a;
	i = all->size_a - 1;
	while (i-- > 0)
	{
		if (cursor->index > cursor->next->index)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

int	unsorted_len(t_node *stack)
{
	t_node	*tmp;
	int		len;
	int		flag;

	len = 0;
	flag = stack->flag;
	tmp = stack;
	while (tmp->flag == flag && flag != -1)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
