/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:51:36 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/05 14:59:06 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int		is_valid_argument(char *str);
int		contains_space(char *str);
void	free_split(char **split);
char	**prepare_args(int argc, char **argv, int *count, int *need_free);
int		fill_stack(t_stack *a, char **args, int count);
int		check_duplicates(t_stack *a);
int		parse_args(int argc, char **argv, t_stack *a)
int		check_args(char **args, int count, int need_free);
int		ft_atoi(const char *nbstr);
int		ft_isdigit(char c);
int		ft_strlen(const char *str);
char	**ft_split(const char *str, char c);

typedef struct s_stack
{
	int	*tab;
	int	size;
}	t_stack;

#endif
