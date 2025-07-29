/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:37:51 by wheino            #+#    #+#             */
/*   Updated: 2025/07/29 22:04:41 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

#define TRUE 1
#define FALSE 0

#define NO 1
#define YES -1

typedef struct s_stack
{
	int	max_size;
	int	current_size;
	int *arr;
}			t_stack;


void	free_stack(t_stack *stack);

/* UTILS */
/* error.c */
void	print_error_and_exit(t_stack *stack);

/* check_input.c */
void	check_input_and_parse(int argc, char *argv[], t_stack *stack);
int		count_split_values(char **values);
void	populate_stack(int total_stack_size, char **input_values, t_stack *stack_a, int argc);
char	**validate_and_fill_values(int argc, char *argv[], char **input_values, t_stack *stack_a);
/* parse_input.c */
char	**validate_and_split_input(char *argv, char **input_values, t_stack *stack_a);
int		is_valid_int(char *value_str);

#endif