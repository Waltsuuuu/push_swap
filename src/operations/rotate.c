/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:19:44 by wheino            #+#    #+#             */
/*   Updated: 2025/07/30 16:28:49 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rotate_a(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->current_size < 2)
		return ;
	i = 0;
	temp = stack_a->arr[i];
	while (i + 1 < stack_a->current_size)
	{
		stack_a->arr[i] = stack_a->arr[i + 1];
		i++;
	}
	stack_a->arr[i] = temp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->current_size < 2)
		return ;
	i = 0;
	temp = stack_b->arr[i];
	while (i + 1 < stack_b->current_size)
	{
		stack_b->arr[i] = stack_b->arr[i + 1];
		i++;
	}
	stack_b->arr[i] = temp;
	write(1, "rb\n", 3);
}
