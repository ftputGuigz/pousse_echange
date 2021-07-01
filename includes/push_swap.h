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

int	moves;

typedef	struct s_stack
{
	t_list **a;
	int a_min;
	int a_max;
	t_list **b;
	int b_min;
	int b_max;
}	t_stack;

void	initialize_stack(t_stack *stack);
int		register_datas(int ac, char **av, t_stack *stack);
void	free_stack_ptr(t_stack *stack);
void	del(void *content);
int		add_to_buffer(char ***buf, char *str);
int		input_conformity(char **buf, char *str);
void	push_swap(t_stack *stack);
int		is_sorted(t_list *lst);
void	printnumber(t_list *a, t_list *b);

//LIST MOVEMENTS
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

//SORTING ALGO
void	stacks_min_max(t_stack *stack);
void	sort_mini_list(t_stack *stack, char stack_id);
int		locate_min(t_stack *stack);

#endif
