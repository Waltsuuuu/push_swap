/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:18:39 by wheino            #+#    #+#             */
/*   Updated: 2025/07/30 14:18:21 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //TEST

int	is_sorted(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->current_size)
	{
		j = i + 1;
		while (j < stack->current_size)
		{
			if (stack->arr[i] > stack->arr[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
