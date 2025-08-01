/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:07:25 by wheino            #+#    #+#             */
/*   Updated: 2025/07/30 15:22:10 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input_and_parse(int argc, char *argv[],
			t_stack *stack_a, t_stack *stack_b)
{
	char	**input_values;
	int		total_stack_size;

	input_values = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		input_values = validate_and_split_input(argv[1], input_values, stack_a);
		total_stack_size = count_split_values(input_values);
	}
	if (argc > 2)
	{
		input_values = validate_and_fill_values(argc, argv,
				input_values, stack_a);
		total_stack_size = argc - 1;
	}
	populate_stack(total_stack_size, input_values, stack_a, argc);
	if (has_duplicates(stack_a) == TRUE)
		print_error_and_exit(stack_a, stack_b);
	stack_b->max_size = total_stack_size;
	stack_b->arr = malloc(sizeof(int) * total_stack_size);
	if (!stack_b->arr)
		print_error_and_exit(stack_a, stack_b);
}

int	has_duplicates(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->current_size -1)
	{
		j = i + 1;
		while (j < stack_a->current_size)
		{
			if (stack_a->arr[i] == stack_a->arr[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	count_split_values(char **values)
{
	int	i;

	i = 0;
	while (values[i] != NULL)
		i++;
	return (i);
}

void	populate_stack(int total_stack_size, char **input_values,
		t_stack *stack_a, int argc)
{
	int	i;

	stack_a->max_size = total_stack_size;
	stack_a->current_size = total_stack_size;
	stack_a->arr = malloc(sizeof(int) * total_stack_size);
	if (!stack_a->arr)
	{
		free(input_values);
		print_error_and_exit(stack_a, NULL);
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
}
