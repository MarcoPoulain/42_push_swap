/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:48:15 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/06 16:46:23 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

static int	handle_error(char **args, int need_free)
{
	write(2, "Error\n", 6);
	if (need_free)
		free_split(args);
	return (0);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	char	**args;
	int		count;
	int		need_free;

	args = prepare_args(argc, argv, &count, &need_free);
	if (!args)
		return (0);
	if (!check_args(args, count, need_free))
		return (0);
	if (!fill_stack(a, args, count))
		return (handle_error(args, need_free));
	if (!check_duplicates(a))
	{
		free(a->tab);
		return (handle_error(args, need_free));
	}
	if (need_free)
		free_split(args);
	return (1);
}
