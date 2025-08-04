/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:46:09 by wheino            #+#    #+#             */
/*   Updated: 2025/08/04 12:51:42 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize(t_stack *stack_a, t_stack *stack_b)
{
	int	*arr;

	arr = malloc(sizeof(int) * stack_a->max_size);
	if (!arr)
		print_error_and_exit(stack_a, stack_b);
	ft_memcpy(arr, stack_a->arr, (sizeof(int) * stack_a->max_size));
	bubble_sort_arr(arr, stack_a->max_size);
	convert_val_to_index(stack_a, arr);
	free(arr);
	arr = NULL;
}

void	convert_val_to_index(t_stack *stack_a, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->max_size)
	{
		j = 0;
		while (j < stack_a->max_size)
		{
			if (arr[j] == stack_a->arr[i])
			{
				stack_a->arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	bubble_sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
