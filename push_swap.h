/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:53:30 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/20 16:00:31 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				num;
	int				index;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_all
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
	int				min;
	int				med;
	int				max;
	int				min_a;
}					t_all;

// push_swap.c 
void	parsing(char **argv, t_all *all);
void	sorting(t_all *all);

// sort_big.c
void	big_sort(t_all *all);
void	sort_five_b_to_a(t_all *all);
void	sort_five_a_to_b(t_all *all);
void	sort_three_b_and_merge(t_all *all, int flag);

// sort_move.c
void	initial_move_a_to_b(t_all *all);
void	move_min_from_b_to_down_a(t_all *all);
void	move_a_to_b(t_all *all);
void	move_b_to_a(t_all *all);

// sort_utils.c
void	set_max_med_min_a(t_all *all);
void	set_max_med_min_b(t_all *all);
void	search_min_a_to_b(t_all *all);
int		search_min_b_to_a(t_all *all);
void	push_down_a(t_all *all);

// parsing_checks.c
char	**get_line(char **argv);
void	check_arg(char **arr);
void	check_doubles(char **arr);
void	free_arr(char **arr, int flag);
void	error(void);

// parsing_initialize.c
void	initialize_struct(t_all *all, int arr_size);
void	fill_stack(char **arr, t_all *all, int arr_size);
void	random_to_ranked(int *numbers, int *rank, int size);
void	create_stack(t_all *all, int *numbers, int *rank, int size);

// stack_utils.c
t_node	*new_node(int num, int rank);
void	lstadd_back_doubly(t_node **stack_a, t_node *node);
void	free_stack(t_all *all, int flag);
int		is_sorted(t_all *all);
int		unsorted_len(t_node *stack);

// sort_mini.c
void	sort_three_a(t_all *all, int flag);
void	sort_five_a(t_all *all);
void	sort_three_b(t_all *all);

// operation_push.c
void	pa(t_all *all, int flag);
void	push_a(t_all *all);
void	pb(t_all *all, int flag);
void	push_b(t_all *all);

// operation_swap.c
void	sa(t_all *all, int flag);
void	sb(t_all *all, int flag);
void	ss(t_all *all, int flag);

// operation_rotate.c
void	ra(t_all *all, int flag);
void	rb(t_all *all, int flag);
void	rr(t_all *all, int flag);

// operation_rrotate.c
void	rra(t_all *all, int flag);
void	rrb(t_all *all, int flag);
void	rrr(t_all *all, int flag);

#endif