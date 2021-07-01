/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_metrics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:45:19 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/01 13:45:30 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_a_min_max(t_stack *stack)
{
	t_list *lst;
	int	min;
	int max;

	min = 0;
	max = 0;
	lst = *(stack->a);
	if (lst)
	{	
		min = *((int *)lst->content);
		max = min;
		while (lst)
		{
			if (*((int *)lst->content) < min)
				min = *((int *)lst->content);
			else if (*((int *)lst->content) > max)
				max = *((int *)lst->content);
			lst = lst->next;
		}
	}
	stack->a_min = min;
	stack->a_max = max;
}

static void	stack_b_min_max(t_stack *stack)
{
	t_list *lst;
	int	min;
	int max;

	min = 0;
	max = 0;
	lst = *(stack->b);
	if (lst)
	{	
		min = *((int *)lst->content);
		max = min;
		while (lst)
		{
			if (*((int *)lst->content) < min)
				min = *((int *)lst->content);
			else if (*((int *)lst->content) > max)
				max = *((int *)lst->content);
			lst = lst->next;
		}
	}
	stack->b_min = min;
	stack->b_max = max;
}

void	stacks_min_max(t_stack *stack)
{
	stack_a_min_max(stack);
	stack_b_min_max(stack);
}

int	locate_min(t_stack *stack)
{
	int	position;
	t_list *lst;

	position = 0;
	lst = *(stack->a);
	while (lst && *((int *)lst->content) != stack->a_min)
	{
		position++;
		lst = lst->next;
	}
	return (position);
}
