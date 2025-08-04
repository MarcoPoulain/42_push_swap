/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:59:12 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/04 16:15:43 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nbstr)
{
	int	i;
	int	sign;

	sign = 1;
	if (*nbstr == '+')
		nbstr++;
	else if (*nbstr == '-')
	{
		nbstr++;
		sign = -1;
	}
	i = 0;
	while (*nbstr >= '0' && *nbstr <= '9')
	{
		i = i * 10 + (*nbstr - '0');
		nbstr++;
	}
	return (i * sign);
}
