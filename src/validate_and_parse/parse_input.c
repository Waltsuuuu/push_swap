/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:23:42 by wheino            #+#    #+#             */
/*   Updated: 2025/08/04 17:42:36 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**validate_and_split_input(char *argv, char **input_values,
		t_stack *stack_a)
{
	int		i;

	if (argv[0] == '\0')
		print_error_and_exit(NULL, NULL);
	input_values = ft_split(argv, ' ');
	if (!input_values)
		print_error_and_exit(NULL, NULL);
	i = 0;
	while (input_values[i] != NULL)
	{
		if (is_valid_int(input_values[i]) == FALSE)
		{
			i = 0;
			while (input_values[i] != NULL)
			{
				free(input_values[i]);
				i++;
			}
			free(input_values);
			print_error_and_exit(stack_a, NULL);
		}
		i++;
	}
	return (input_values);
}

char	**validate_and_fill_values(int argc, char *argv[],
		char **input_values, t_stack *stack_a)
{
	int	i;

	input_values = malloc(sizeof(char *) * argc);
	if (!input_values)
		print_error_and_exit(stack_a, NULL);
	i = 1;
	while (i < argc)
	{
		if (is_valid_int(argv[i]) == FALSE || argv[i][0] == '\0')
		{
			free(input_values);
			print_error_and_exit(stack_a, NULL);
		}
		input_values[i - 1] = argv[i];
		i++;
	}
	input_values[i - 1] = NULL;
	return (input_values);
}

int	is_valid_int(char *value_str)
{
	int				i;
	int				neg_sign;
	long long		result;

	i = 0;
	neg_sign = NO;
	result = 0;
	if (value_str[i] == '-' || value_str[i] == '+')
	{
		if (value_str[i + 1] == '\0' || ft_isdigit(value_str[i + 1]) == FALSE)
			return (FALSE);
		if (value_str[i] == '-')
			neg_sign = YES;
		i++;
	}
	while (value_str[i] != '\0')
	{
		if (ft_isdigit(value_str[i]) == FALSE)
			return (FALSE);
		result = result * 10 + (value_str[i++] - '0');
		if (result > INT_MAX || (result * neg_sign) < INT_MIN)
			return (FALSE);
	}
	return (TRUE);
}
