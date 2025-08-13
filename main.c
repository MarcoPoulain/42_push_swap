/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:10:38 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/13 12:55:37 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stack_a))
		return (1);
	if (stack_a.size == 0)
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		return (1);
	}
	stack_b.tab = malloc(sizeof(int) * stack_a.size);
	if (!stack_b.tab)
	{
		free(stack_a.tab);
		return (1);
	}
	stack_b.size = 0;
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
