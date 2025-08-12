/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:51:36 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/12 13:23:56 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	*tab;
	int	size;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
void	move_smallest_to_top(t_stack *stack, char which_stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);
void	bubble_sort(int *tab, int size);
t_stack	*tab_duplicate(t_stack *tabsrc);
void	map_in_place(t_stack *tabsrc, t_stack *duptab);
int		get_bit(unsigned int nbr, int position);
int		max_bits(unsigned int nbr);
int		is_valid_argument(char *str);
int		contains_space(char *str);
void	free_split(char **split);
char	**prepare_args(int argc, char **argv, int *count, int *need_free);
int		fill_stack(t_stack *a, char **args, int count);
int		check_duplicates(t_stack *a);
int		parse_args(int argc, char **argv, t_stack *a);
int		check_args(char **args, int count, int need_free);
int		ft_atoi(const char *nbstr);
int		ft_isdigit(char c);
int		ft_strlen(const char *str);
char	**ft_split(const char *str, char c);

#endif
