/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:31:14 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/11 16:34:17 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack *a, t_stack *b)
{
	t_stack	*duptab;
	int		bit;
	int		bits;
	int		i;
	int		size_init;

	duptab = tab_duplicate(a);
	if (!duptab)
		return ;
	bubble_sort(duptab->tab, duptab->size);
	map_in_place(a, duptab);
	free_stack(duptab);
	bits = max_bits(a->size - 1);
	size_init = a->size;
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < size_init)
		{
			if (get_bit(a->tab[0], bit) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
