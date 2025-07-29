/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:07:25 by wheino            #+#    #+#             */
/*   Updated: 2025/07/29 21:37:33 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //ONLY FOR TESTING

// if argc < 2, error
// if argc == 2, require split
// if argc > 2, no split

void	check_input_and_parse(int argc, char *argv[], t_stack *stack_a)
{
	char	**input_values;
	int		total_stack_size;
	int		i;
	
	input_values = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		input_values = validate_and_split_input(argv[1], input_values, stack_a);
		total_stack_size = count_split_values(input_values);
		populate_stack(total_stack_size, input_values, stack_a, argc);
	}
	if (argc > 2)
	{
		input_values = malloc(sizeof(char *) * argc);
		if (!input_values)
			print_error_and_exit(stack_a);
		i = 1;
		while (i < argc)
		{
			if (is_valid_int(argv[i]) == FALSE)
			{
				free(input_values);
				print_error_and_exit(stack_a);
			}
			input_values[i - 1] = argv[i];
			i++;
		}
		input_values[i - 1] = NULL;
		total_stack_size = argc - 1;
		populate_stack(total_stack_size, input_values, stack_a, argc);
	}
}

int	count_split_values(char **values)
{
	int	i;

	i = 0;
	while (values[i] != NULL)
		i++;
	return (i);
}

void	populate_stack(int total_stack_size, char **input_values, t_stack *stack_a, int argc)
{
	int	i;
	
	stack_a->max_size = total_stack_size;
	stack_a->arr = malloc(sizeof(int) * total_stack_size);;
	if (!stack_a->arr)
	{
		free(input_values);
		print_error_and_exit(stack_a);
	}
	i = 0;
	while (i < total_stack_size)
	{
		stack_a->arr[i] = ft_atoi(input_values[i]);
		if (argc == 2)
			free(input_values[i]);
		i++;
	}
	free(input_values);
	input_values = NULL;
	stack_a->current_size = total_stack_size;
}
