/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:10:38 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/05 15:13:07 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		printf("%d\n", stack->tab[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stack_a))
		return (1);

	print_stack(&stack_a); // pour debug uniquement

	free(stack_a.tab);
	return (0);
}
