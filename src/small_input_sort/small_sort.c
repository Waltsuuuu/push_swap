/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:19:07 by wheino            #+#    #+#             */
/*   Updated: 2025/07/31 20:37:15 by wheino           ###   ########.fr       */
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
	int	values_pushed_to_b;
	int	next_smallest_to_push;
	
	values_pushed_to_b = 0;
	next_smallest_to_push = 0;
	while (stack_a->current_size > 3)
	{
		while (stack_a->arr[0] != next_smallest_to_push)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
		values_pushed_to_b++;
		next_smallest_to_push++;
	}

	sort_3(stack_a);
	if (values_pushed_to_b == 2 &&
			stack_b->arr[0] < stack_b->arr[1])
		swap_b(stack_b);
	while (values_pushed_to_b > 0)
	{
		push_a(stack_a, stack_b);
		values_pushed_to_b--;
	}
}

