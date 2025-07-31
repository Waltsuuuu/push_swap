/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:36:45 by wheino            #+#    #+#             */
/*   Updated: 2025/07/31 16:35:43 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->current_size == 0)
		return ;
	i = stack_a->current_size;
	while (i > 0)
	{
		stack_a->arr[i] = stack_a->arr[i - 1];
		i--;
	}
	stack_a->arr[0] = stack_b->arr[0];
	i = 0;
	while (i < stack_b->current_size - 1)
	{
		stack_b->arr[i] = stack_b->arr[i + 1];
		i++;
	}
	stack_b->current_size--;
	stack_a->current_size++;
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->current_size == 0)
		return ;
	i = stack_b->current_size;
	while (i > 0)
	{
		stack_b->arr[i] = stack_b->arr[i - 1];
		i--;
	}
	stack_b->arr[0] = stack_a->arr[0];
	i = 0;
	while (i < stack_a->current_size - 1)
	{
		stack_a->arr[i] = stack_a->arr[i + 1];
		i++;
	}
	stack_a->current_size--;
	stack_b->current_size++;
	write(1, "pb\n", 3);
}
