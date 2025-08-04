/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:53:52 by wheino            #+#    #+#             */
/*   Updated: 2025/08/04 17:01:50 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_index(t_stack *stack_a)
{
	int	smallest;
	int	smallest_index;
	int	i;

	smallest = stack_a->arr[0];
	smallest_index = 0;
	i = 1;
	while (i < stack_a->current_size)
	{
		if (stack_a->arr[i] < smallest)
		{
			smallest = stack_a->arr[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

void	smallest_to_top(t_stack *stack_a)
{
	int	smallest_index;

	smallest_index = find_smallest_index(stack_a);
	if (smallest_index <= (stack_a->current_size / 2))
	{
		while (smallest_index > 0)
		{
			rotate_a(stack_a);
			smallest_index--;
		}
	}
	else
	{
		while (smallest_index < stack_a->current_size)
		{
			rev_rotate_a(stack_a);
			smallest_index++;
		}
	}
}
