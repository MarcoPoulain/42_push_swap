/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:26:53 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/06 14:45:43 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	rotate(t_stack *s)
{
	int	first;
	int	i;

	if (s->size >= 2)
	{
		first = s->tab[0];
		i = 0;
		while (i < s->size - 1)
		{
			s->tab[i] = s->tab[i + 1];
			i++;
		}
		s->tab[s->size - 1] = first;
	}
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
