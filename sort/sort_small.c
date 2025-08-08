/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:39:59 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/08 14:47:13 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack *a)
{
	int	first;
	int	second;

	if (a->size != 2)
		return ;
	first = a->tab[0];
	second = a->tab[1];
	if (first > second)
		sa(a);
}

static void	sort_3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size != 3)
		return ;
	first = a->tab[0];
	second = a->tab[1];
	third = a->tab[2];
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	sort_4(t_stack *a, t_stack *b)
{
	move_smallest_to_top(a, 'a');
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void	sort_5(t_stack *a, t_stack *b)
{
	move_smallest_to_top(a, 'a');
	pb(a, b);
	move_smallest_to_top(a, 'a');
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
}
