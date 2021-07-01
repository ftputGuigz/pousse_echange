/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:39:27 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/30 17:39:29 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*identify_lst(t_stack *stack, char stack_id)
{
	t_list *lst;

	if (stack_id == 'a')
		lst = *(stack->a);
	else
		lst = *(stack->b);
	return (lst);	
}
void	get_a_b_c(int *a, int *b, int *c, t_list *lst)
{
	*a = *((int *)(lst->content));
	*b = *((int *)(lst->next->content));
	*c = *((int *)(lst->next->next->content));
}

void	rotate_head(t_stack *stack, char stack_id)
{
	if (stack_id == 'a')
		sa(stack);
	else
		sb(stack);
}

static void	move_list_down(t_stack *stack, char stack_id)
{
	if (stack_id == 'a')
		rra(stack);
	else
		rrb(stack);
}

static void	move_list_up(t_stack *stack, char stack_id)
{
	if (stack_id == 'a')
		ra(stack);
	else
		rb(stack);
}

void	sort_mini_list(t_stack *stack, char stack_id)
{
	t_list *lst;
	int		a;
	int		b;
	int		c;

	lst = identify_lst(stack, stack_id);
	get_a_b_c(&a, &b, &c, lst);
	if (!((a < b && b < c) || (a > b && b < c && a > c) || \
	(a < b && b > c && a > c)))
		rotate_head(stack, stack_id);
	lst = identify_lst(stack, stack_id);
	get_a_b_c(&a, &b, &c, lst);
	if (b > a && b > c)
		move_list_down(stack, stack_id);
	if (b < a && b < c)
		move_list_up(stack, stack_id);
}
