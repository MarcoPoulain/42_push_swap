/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:06:42 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/08 14:58:01 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_index(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stack->tab[0];
	index = 0;
	while (i < stack->size)
	{
		if (stack->tab[i] < min)
		{
			min = stack->tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static void	move_smallest_up(t_stack *stack, int index, char which_stack)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (which_stack == 'a')
			ra(stack);
		else
			rb(stack);
		i++;
	}
}

static void	move_smallest_down(t_stack *stack, int index, char which_stack)
{
	int	i;
	int	limit;

	i = 0;
	limit = stack->size - index;
	while (i < limit)
	{
		if (which_stack == 'a')
			rra(stack);
		else
			rrb(stack);
		i++;
	}

}

void	move_smallest_to_top(t_stack *stack, char which_stack)
{
	int	index;

	index = find_smallest_index(stack);
	if (index <= stack->size / 2)
		move_smallest_up(stack, index, which_stack);
	else
		move_smallest_down(stack, index, which_stack);
}
