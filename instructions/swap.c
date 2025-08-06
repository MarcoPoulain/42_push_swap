/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:49:32 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/06 13:08:38 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	ft_swap(t_stack *s)
{
	int	tmp;

	if (s->size >= 2)
	{
		tmp = s->tab[0];
		s->tab[0] = s->tab[1];
		s->tab[1] = tmp;
	}
}

void	sa(t_stack *a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
