/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:21:09 by anikitin          #+#    #+#             */
/*   Updated: 2024/09/26 18:28:44 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_line(char **argv)
{
	int		i;
	char	*line;
	char	*tmp;
	char	**arr;

	line = ft_strdup(argv[1]);
	i = 1;
	while (argv[++i])
	{
		tmp = line;
		line = ft_strjoin(line, " ");
		free(tmp);
		tmp = line;
		line = ft_strjoin(line, argv[i]);
		free(tmp);
	}
	arr = ft_split(line, ' ');
	free(line);
	return (arr);
}

void	check_arg(char **arr, t_all *all)
{
	int			i;
	int			j;
	long long	num;

	i = -1;
	while (arr[++i])
	{
		j = 0;
		if (arr[i][j] == '-')
			j++;
		while (arr[i][j] && ft_isdigit(arr[i][j]))
			j++;
		if (arr[i][j])
		{
			free_arr(arr);
			free_stack(all, 1);
		}
		num = ft_atoi(arr[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_arr(arr);
			free_stack(all, 1);
		}
	}
}

void	check_doubles(char **arr, t_all *all)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
			{
				free_arr(arr);
				free_stack(all, 1);
			}
			j++;
		}
		i++;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
