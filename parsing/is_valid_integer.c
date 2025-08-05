/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:58:28 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/05 12:38:40 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_int(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
			str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{	
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

static char	*chose_int_limit(char *str)
{
	if (*str == '-')
		return ("2147483648");
	return ("2147483647");
}

static int	is_int_range(char *str)
{
	char	*limit;
	int		len;
	int		i;

	if (*str == '+' || *str == '-')
		str++;
	len = ft_strlen(str);
	if (len < 10)
		return (1);
	if (len > 10)
		return (0);
	limit = chose_int_limit(str - 1);
	i = 0;
	while (str[i])
	{
		if (str[i] > limit[i])
			return (0);
		if (str[i] < limit[i])
			break ;
		i++;
	}
	return (1);
}

int	is_valid_argument(char *str)
{
	if (!is_valid_int(str))
		return (0);
	if (!is_int_range(str))
		return (0);
	return (1);
}

int	contains_space(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
char	**args;
int		i;
	if (argc == 2)
	{
		if (!contains_space(argv[1]))
			if (!is_valid_argument(argv[1]))
				printf("\"%s\" non valide\n", argv[1]);
			else
				printf("\"%s\" valide\n", argv[1]);
		else
		{
			args = ft_split(argv[1], ' ');
			i = 0;
			while (args[i])
			{
				if (!is_valid_argument(args[i]))
				{
					printf("\"%s\" non valide\n", args[i]);
					break ;
				}
				i++;
			}
			printf("Tout est valide\n");
		}
	}
	else
		printf("error\n");
	return (0);
}
*/
