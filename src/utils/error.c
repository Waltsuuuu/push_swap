/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:40:59 by wheino            #+#    #+#             */
/*   Updated: 2025/07/29 20:30:29 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(t_stack *stack)
{
	write(2, "Error\n", 6);
	if (stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}
