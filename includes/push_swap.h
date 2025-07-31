/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:37:51 by wheino            #+#    #+#             */
/*   Updated: 2025/07/31 20:37:22 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define TRUE 1
# define FALSE 0

# define NO 1
# define YES -1

typedef struct s_stack
{
	int	max_size;
	int	current_size;
	int	*arr;
}			t_stack;

/* UTILS */
/* exit.c */
void	print_error_and_exit(t_stack *stack_a, t_stack *stack_b);
void	clean_and_exit(t_stack *stack_a, t_stack *stack_b);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

/* is_sorted.c */
int		is_sorted(t_stack *stack);

/* VALIDATE AND PARSE */
/* check_input.c */
void	check_input_and_parse(int argc, char *argv[],
			t_stack *stack, t_stack *stack_b);
int		count_split_values(char **values);
void	populate_stack(int total_stack_size, char **input_values,
			t_stack *stack_a, int argc);
char	**validate_and_fill_values(int argc, char *argv[],
			char **input_values, t_stack *stack_a);
int		has_duplicates(t_stack *stack_a);

/* parse_input.c */
char	**validate_and_split_input(char *argv, char **input_values,
			t_stack *stack_a);
int		is_valid_int(char *value_str);

/* OPERATIONS */
/* swap.c */
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_swap(t_stack *stack_a, t_stack *stack_b);

/* roatate.c */
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	rotate_rotate(t_stack *stack_a, t_stack *stack_b);

/* rev_rotate.c */
void	rev_rotate_a(t_stack *stack_a);
void	rev_rotate_b(t_stack *stack_b);
void	rev_rotate_rotate(t_stack *stack_a, t_stack *stack_b);

/* push.c */
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

/* NORMALIZE */
/* normalize.c */
void	normalize(t_stack *stack_a, t_stack *stack_b);
void	bubble_sort_arr(int *arr, int size);
void	convert_val_to_index(t_stack *stack_a, int *arr);

/* RADIX SORT */
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
int		find_max_bit(t_stack *stack_a);

/* SMALL INPUT SORT */
/* small_sort.c */
void	small_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_2(t_stack *stack_a);
void	sort_3(t_stack *stack_a);
void	sort_4_5(t_stack *stack_a, t_stack *stack_b);

#endif