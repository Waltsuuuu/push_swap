/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:19:07 by wheino            #+#    #+#             */
/*   Updated: 2025/08/04 16:45:01 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->max_size == 2)
		sort_2(stack_a);
	else if (stack_a->max_size == 3)
		sort_3(stack_a);
	else if (stack_a->max_size <= 5)
		sort_4_5(stack_a, stack_b);
}

void	sort_2(t_stack *stack_a)
{
	swap_a(stack_a);
}

void	sort_3(t_stack *stack_a)
{
	if (stack_a->arr[0] < stack_a->arr[2] &&
			stack_a->arr[2] < stack_a->arr[1])
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (stack_a->arr[1] < stack_a->arr[0] &&
			stack_a->arr[0] < stack_a->arr[2])
		swap_a(stack_a);
	else if (stack_a->arr[1] < stack_a->arr[2] &&
			stack_a->arr[2] < stack_a->arr[0])
		rotate_a(stack_a);
	else if (stack_a->arr[2] < stack_a->arr[0] &&
			stack_a->arr[0] < stack_a->arr[1])
		rev_rotate_a(stack_a);
	else if (stack_a->arr[2] < stack_a->arr[1] &&
			stack_a->arr[1] < stack_a->arr[0])
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
}

void	sort_4_5(t_stack *stack_a, t_stack *stack_b)
{
	int	push_count;
	int	next_smallest_to_push;
	
	push_count = stack_a->current_size - 3;
	next_smallest_to_push = 0;
	while (push_count > 0)
	{
		smallest_to_top(stack_a);
		push_b(stack_a, stack_b);
		push_count--;
	}
	sort_3(stack_a);
	// if (push_count == 2 &&
	// 		stack_b->arr[0] < stack_b->arr[1])
	// 	swap_b(stack_b);
	while (stack_b->current_size > 0)
		push_a(stack_a, stack_b);
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
