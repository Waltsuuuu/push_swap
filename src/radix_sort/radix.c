/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:00:35 by wheino            #+#    #+#             */
/*   Updated: 2025/07/31 16:22:45 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bit;
	int	bit_index;
	int	i;
	
	bit_index = 0;
	max_bit = find_max_bit(stack_a);
	while (bit_index < max_bit) // Loop through each bit (LSB to MSB)
	{
		i = 0;
		while (i < stack_a->max_size) //Check bit and push to B if the bit == 0, else rotate_a.
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
		while (stack_b->current_size != 0) //Push everything back to A.
			push_a(stack_a, stack_b);
		bit_index++;
	}
}
/* Finds the number of bits needed to represent the largest index number in the stack */
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