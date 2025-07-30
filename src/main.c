/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:43:08 by wheino            #+#    #+#             */
/*   Updated: 2025/07/30 15:08:44 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //TESTING ONLY

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	ft_memset(&stack_a, 0, sizeof(t_stack));
	ft_memset(&stack_b, 0, sizeof(t_stack));
	check_input_and_parse(argc, argv, &stack_a, &stack_b);
	if (is_sorted(&stack_a) == TRUE)
		clean_and_exit(&stack_a, &stack_b);
	int i = 0;
	while (i < stack_a.current_size)
	{
		printf("arr[%d] = %d\n", i, stack_a.arr[i]);
		i++;
	}
	swap_a(&stack_a);
	i = 0;
	while (i < stack_a.current_size)
	{
		printf("arr[%d] = %d\n", i, stack_a.arr[i]);
		i++;
	}
	clean_and_exit(&stack_a, &stack_b);
}
