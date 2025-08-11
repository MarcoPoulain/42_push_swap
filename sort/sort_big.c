/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:31:14 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/11 17:04:44 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	handle_error_stacks(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(EXIT_FAILURE);
}

static void	process_bit(t_stack *a, t_stack *b, int bit, int size_init)
{
	int	i;

	i = 0;
	while (i < size_init)
	{
		if (get_bit(a->tab[0], bit) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	t_stack	*duptab;
	int		bit;
	int		bits;
	int		size_init;

	duptab = tab_duplicate(a);
	if (!duptab)
		handle_error_stacks(a, b);
	bubble_sort(duptab->tab, duptab->size);
	map_in_place(a, duptab);
	free_stack(duptab);
	bits = max_bits(a->size - 1);
	size_init = a->size;
	bit = 0;
	while (bit < bits)
	{
		process_bit(a, b, bit, size_init);
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
