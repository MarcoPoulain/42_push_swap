/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:58:28 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/13 16:17:06 by kassassi         ###   ########.fr       */
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

static char	*skip_sign_zeros(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0' && str[1] != '\0')
		str++;
	return (str);
}

static int	is_int_range(char *str)
{
	char	*limit;
	char	*original;
	int		len;
	int		i;

	original = str;
	str = skip_sign_zeros(str);
	len = ft_strlen(str);
	if (len < 10)
		return (1);
	if (len > 10)
		return (0);
	limit = chose_int_limit(original);
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
