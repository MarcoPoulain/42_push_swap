/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:36:20 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/05 15:02:10 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**prepare_args(int argc, char **argv, int *count, int *need_free)
{
	char	**args;
	int		i;

	*need_free = 0;
	if (argc == 2 && contains_space(argv[1]))
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
		*need_free = 1;
		*count = 0;
		while (args[*count])
			(*count)++;
	}
	else
	{
		args = &argv[1];
		*count = argc - 1;
	}
	return (args);
}

int	check_args(char **args, int count, int need_free)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_valid_argument(args[i]))
		{
			write(2, "Error\n", 6);
			if (need_free)
				free_split(args);
			return (0);
		}
		i++;
	}
	return (1);
}

int	fill_stack(t_stack *a, char **args, int count)
{
	int	i;

	a->tab = malloc(sizeof(int) * count);
	if (!a->tab)
		return (0);
	i = 0;
	while (i < count)
	{
		a->tab[i] = ft_atoi(args[i]);
		i++;
	}
	a->size = count;
	return (1);
}

int	check_duplicates(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->tab[i] == a->tab[j])
				return (0);
			j++;
		}
		i++;
	}
}
