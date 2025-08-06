/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:10:38 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/06 15:37:29 by kassassi         ###   ########.fr       */
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
	t_stack stack_b;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stack_a))
		return (1);

	stack_b.tab = malloc(sizeof(int) * stack_a.size);
	if (!stack_b.tab)
	{
		free(stack_a.tab);
		return (1);
	}
	stack_b.size = 0;
	printf("size stack a: %d\n", stack_a.size);
	print_stack(&stack_a);
	print_stack(&stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ra(&stack_a);
	rrb(&stack_b);
	print_stack(&stack_a);
	printf("size stack a: %d\n", stack_a.size);
	print_stack(&stack_b);

	free(stack_a.tab);
	free(stack_b.tab);
	return (0);
}
