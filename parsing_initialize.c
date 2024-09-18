/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_initialize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:08:25 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/18 11:08:28 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initialize_struct(t_all *all, int arr_size)
{
    all->stack_a = NULL;
    all->stack_b = NULL;
    all->size_a = arr_size;
    all->size_b = 0;
    all->min_a = 1;
}

void fill_stack(char **arr, t_all *all, int arr_size)
{
    int *numbers;
    int *rank;
    int i;
    
    numbers = malloc(sizeof(int) * arr_size);
    rank = malloc(sizeof(int) * arr_size);
    i = 0;
    while (i < arr_size)
    {
        numbers[i] = ft_atoi(arr[i]);
        i++;
    }
    random_to_ranked(numbers, rank, arr_size);
    create_stack(all, numbers, rank, arr_size);
}

void random_to_ranked(int *numbers, int *rank, int size)
{
    int i;
    int j;
    int count_smaller;

    i = 0;
    while (i < size)
    {
        j = 0;
        count_smaller = 1;
        while (j < size)
        {
            if (numbers[j] < numbers[i])
                count_smaller++;
            j++;
        }
        rank[i] = count_smaller;
        i++;
    }
}
void create_stack(t_all *all, int *numbers, int *rank, int size)
{
    int i = 0;

    while (i < size)
    {
        lstadd_back_doubly(&all->stack_a, new_node(numbers[i], rank[i]));
        i++;
    }
    free(numbers);
    free(rank);
}