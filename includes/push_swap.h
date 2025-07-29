/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:37:51 by wheino            #+#    #+#             */
/*   Updated: 2025/07/29 18:44:57 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

#define TRUE 1
#define FALSE 0

#define NO 1
#define YES -1

/* UTILS */
/* error.c */
void	print_error_and_exit(void);

/* check_args.c */
void	check_input_and_parse(int argc, char *argv[]);
int	count_split_values(char **values);

/* parse_input.c */
char	**validate_and_split_input(int argc, char *argv, char **input_values);
int		is_valid_int(char *value_str);

#endif