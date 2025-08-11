/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:21:14 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/11 16:27:55 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	swapped;

	i = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

t_stack	*tab_duplicate(t_stack *tabsrc)
{
	t_stack	*tabdest;
	int		i;

	tabdest = malloc(sizeof(t_stack));
	if (!tabdest)
		return (NULL);
	tabdest->size = tabsrc->size;
	tabdest->tab = malloc(sizeof(int) * tabdest->size);
	if (!tabdest->tab)
	{
		free(tabdest);
		return (NULL);
	}
	i = 0;
	while (i < tabdest->size)
	{
		tabdest->tab[i] = tabsrc->tab[i];
		i++;
	}
	return (tabdest);
}

void	map_in_place(t_stack *tabsrc, t_stack *duptab)
{
	int		i;
	int		j;

	i = 0;
	while (i < tabsrc->size)
	{
		j = 0;
		while (j < duptab->size)
		{
			if (tabsrc->tab[i] == duptab->tab[j])
			{
				tabsrc->tab[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	get_bit(unsigned int nbr, int position)
{
	int	bit;

	bit = (nbr >> position) & 1;
	return (bit);
}

int	max_bits(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr >> 1;
		count++;
	}
	return (count);
}
