/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:30:18 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/06 16:45:56 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	push(t_stack *src, t_stack *dest)
{
	int	i;

	if (src->size > 0)
	{
		i = dest->size;
		while (i > 0)
		{
			dest->tab[i] = dest->tab[i - 1];
			i--;
		}
		dest->tab[0] = src->tab[0];
		dest->size++;
		i = 0;
		while (i < src->size - 1)
		{
			src->tab[i] = src->tab[i + 1];
			i++;
		}
		src->size--;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
