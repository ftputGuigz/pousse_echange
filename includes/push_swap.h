/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:05:12 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/23 14:55:42 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	t_list	**a;
	int		a_min;
	int		a_max;
	t_list	**b;
	int		b_min;
	int		b_max;
	t_list	**output;
}	t_stack;

int		initialize_stack(t_stack *stack);
int		register_datas(char **av, t_stack *stack);
void	free_stack_ptr(t_stack *stack);
void	del(void *content);
int		add_to_buffer(int ***buf, char *str);
int		input_conformity(int **buf, char *str);
int		push_swap(t_stack *stack);
int		is_sorted(t_list *lst);
void	printnumber(t_list *a, t_list *b);
void	print_stack_output(t_stack *stack);
int		get_first_stack_elem(t_list *lst);
void	sort_3_to_5(t_stack *stack);
int		init_stack_a(int nb, t_stack *stack);

//LIST MOVEMENTS
int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack);
int		pa(t_stack *stack);
int		pb(t_stack *stack);
int		ra(t_stack *stack);
int		rb(t_stack *stack);
int		rr(t_stack *stack);
int		rra(t_stack *stack);
int		rrb(t_stack *stack);
int		rrr(t_stack *stack);

//SORTING ALGO
void	stacks_min_max(t_stack *stack);
int		sort_mini_list(t_stack *stack, char stack_id);
int		locate_min(t_stack *stack, char stack_id);
int		locate_max(t_stack *stack, char char_id);
int		sort_big_list(t_stack *stack);
int		order_list(t_stack *stack);
int		max_distance_to_exit(t_stack *stack);
int		min_distance_to_exit(t_stack *stack);
int		median_distance_to_exit(int median, t_stack *stack);
int		rotate_b_down(int moves, t_stack *stack);
int		rotate_b_up(int moves, t_stack *stack);
int		*search_median(t_stack *stack);
void	first_under_median_goes_b(int oldmedian, int median, t_stack *stack);
int		under_median_goes_b(int oldmedian, int median, t_stack *stack);
int		higher_median_goes_b(int median, t_stack *stack);
int		pushback_to_a(t_stack *stack);

#endif
