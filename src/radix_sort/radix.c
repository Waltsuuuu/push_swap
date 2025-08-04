/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:00:35 by wheino            #+#    #+#             */
/*   Updated: 2025/08/04 12:51:31 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bit;
	int	bit_index;
	int	i;
	
	bit_index = 0;
	max_bit = find_max_bit(stack_a);
	while (bit_index < max_bit) 
	{
		i = 0;
		while (i < stack_a->max_size)
		{
			if (((stack_a->arr[0] >> bit_index) & 1) == 0)
			{
				push_b(stack_a, stack_b);
			}
			else
			{
				rotate_a(stack_a);
			}
			i++;
		}
		while (stack_b->current_size != 0)
			push_a(stack_a, stack_b);
		bit_index++;
	}
}

int	find_max_bit(t_stack *stack_a)
{
	int	largest_index;
	int	max_bit;

	largest_index = stack_a->max_size - 1;
	max_bit = 0;
	while (largest_index >> max_bit)
		max_bit++;
	return (max_bit);
}