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
	t_list	*lst;

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

int	rotate_head(t_stack *stack, char stack_id)
{
	int	ret;

	if (stack_id == 'a')
		ret = sa(stack);
	else
		ret = sb(stack);
	return (ret);
}

int	sort_mini_list(t_stack *stack, char stack_id)
{
	t_list	*lst;
	int		a;
	int		b;
	int		c;

	lst = identify_lst(stack, stack_id);
	get_a_b_c(&a, &b, &c, lst);
	if (!((a < b && b < c) || (a > b && b < c && a > c) || \
	(a < b && b > c && a > c)))
		return (rotate_head(stack, stack_id));
	return (1);
}
