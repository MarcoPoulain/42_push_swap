/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:50:22 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/04 17:22:51 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int	ft_wordsnbr(const char *str, char c)
{
	int	wordscount;

	wordscount = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			wordscount++;
			while (*str && *str != c)
				str++;
		}
	}
	return (wordscount);
}

static char	*ft_wordalloc(const char *str, char c)
{
	int		charcount;
	char	*wordalloc;

	charcount = 0;
	while (*str && *str != c)
	{
		charcount ++;
		str++;
	}
	wordalloc = malloc(sizeof(char) * (charcount + 1));
	if (!wordalloc)
		return (NULL);
	return (wordalloc);
}

static char	**ft_freeall(char **tab, int limit)
{
	while (limit > 0)
		free(tab[--limit]);
	free(tab);
	return (NULL);
}

static char	**ft_taballoc(const char *str, int size, char c)
{
	char	**wordstab;
	int		i;

	i = 0;
	wordstab = malloc(sizeof(char *) * (size + 1));
	if (!wordstab)
		return (NULL);
	while (*str && i < size)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			wordstab[i] = ft_wordalloc(str, c);
			if (!wordstab[i])
				return (ft_freeall(wordstab, i));
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	wordstab[i] = NULL;
	return (wordstab);
}

char	**ft_split(const char *str, char c)
{
	char	**wordstab;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	wordstab = ft_taballoc(str, ft_wordsnbr(str, c), c);
	if (!wordstab)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			j = 0;
			while (*str && *str != c)
				wordstab[i][j++] = *str++;
			wordstab[i][j] = '\0';
			i++;
		}
	}
	return (wordstab);
}
