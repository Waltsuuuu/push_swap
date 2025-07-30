/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:28:19 by wheino            #+#    #+#             */
/*   Updated: 2025/07/30 16:27:01 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int	temp;

	if (stack_a->current_size <= 1)
		return ;
	temp = stack_a->arr[0];
	stack_a->arr[0] = stack_a->arr[1];
	stack_a->arr[1] = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b)
{
	int	temp;

	if (stack_b->current_size <= 1)
		return ;
	temp = stack_b->arr[0];
	stack_b->arr[0] = stack_b->arr[1];
	stack_b->arr[1] = temp;
	write(1, "sb\n", 3);
}

void	swap_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (!(stack_a->current_size <= 1))
	{
		temp = stack_a->arr[0];
		stack_a->arr[0] = stack_a->arr[1];
		stack_a->arr[1] = temp;
	}
	if (!(stack_b->current_size <= 1))
	{
		temp = stack_b->arr[0];
		stack_b->arr[0] = stack_b->arr[1];
		stack_b->arr[1] = temp;
	}
	write(1, "ss\n", 3);
}
