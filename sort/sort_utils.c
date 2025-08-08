/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:59:11 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/08 15:08:50 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	if (stack->tab)
		free(stack->tab);
	stack->tab = NULL;
	stack->size = 0;
}
