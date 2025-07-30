/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:40:59 by wheino            #+#    #+#             */
/*   Updated: 2025/07/30 14:18:44 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(t_stack *stack_a, t_stack *stack_b)
{
	write(2, "Error\n", 6);
	if (stack_a || stack_b)
		free_stacks(stack_a, stack_b);
	exit(EXIT_FAILURE);
}

void	clean_and_exit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a || stack_b)
		free_stacks(stack_a, stack_b);
	exit(EXIT_SUCCESS);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->arr != NULL)
	{
		free(stack_a->arr);
		stack_a->arr = NULL;
	}
	if (stack_b && stack_b->arr != NULL)
	{
		free(stack_b->arr);
		stack_b->arr = NULL;
	}
}
