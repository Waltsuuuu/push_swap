/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:07:25 by wheino            #+#    #+#             */
/*   Updated: 2025/07/29 18:47:17 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //ONLY FOR TESTING


// if argc < 2, error
// if argc == 2, require split
// if argc > 2, no split

void	check_input_and_parse(int argc, char *argv[])
{
	char	**input_values;
	int		total_stack_size;
	input_values = NULL;
	if (argc < 2)
		print_error_and_exit();
	if (argc == 2)
	{
		input_values = validate_and_split_input(argc, argv[1], input_values);
		total_stack_size = count_split_values(input_values);
	}
	// if (argc > 2)
		//loop through each arg and make sure its valid int.
		//convert and store the input (str to int)
		//check for duplicates
}

int	count_split_values(char **values)
{
	int	i;

	i = 0;
	while (values[i] != NULL)
		i++;
	return (i);
}
