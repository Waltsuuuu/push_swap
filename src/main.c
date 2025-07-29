/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:43:08 by wheino            #+#    #+#             */
/*   Updated: 2025/07/29 20:36:22 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //TESTING ONLY

int	main(int argc, char *argv[])
{
	t_stack stack_a;
	
	stack_a.arr = NULL;
	check_input_and_parse(argc, argv, &stack_a);
	int i = 0;
	while (i < stack_a.current_size)
	{
		printf("%d\n", stack_a.arr[i]);
		i++;
	}

	free_stack(&stack_a);
	return (EXIT_SUCCESS);
}

void	free_stack(t_stack *stack)
{
	if (stack->arr == NULL)
		return ;
	free(stack->arr);
	stack->arr = NULL;
}
