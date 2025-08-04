/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:12:28 by wheino            #+#    #+#             */
/*   Updated: 2025/08/04 12:51:49 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->current_size < 2)
		return ;
	i = stack_a->current_size - 1;
	temp = stack_a->arr[i];
	while (i > 0)
	{
		stack_a->arr[i] = stack_a->arr[i - 1];
		i--;
	}
	stack_a->arr[i] = temp;
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->current_size < 2)
		return ;
	i = stack_b->current_size - 1;
	temp = stack_b->arr[i];
	while (i > 0)
	{
		stack_b->arr[i] = stack_b->arr[i - 1];
		i--;
	}
	stack_b->arr[i] = temp;
	write(1, "rrb\n", 4);
}

void	rev_rotate_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;

	if (!(stack_b->current_size < 2))
	{
		i = stack_b->current_size;
		temp = stack_b->arr[i - 1];
		while (--i > 0)
			stack_b->arr[i] = stack_b->arr[i - 1];
		stack_b->arr[i] = temp;
	}
	if (!(stack_a->current_size < 2))
	{
		i = stack_a->current_size;
		temp = stack_a->arr[i - 1];
		while (--i > 0)
			stack_a->arr[i] = stack_a->arr[i - 1];
		stack_a->arr[i] = temp;
	}
	write(1, "rrr\n", 4);
}
