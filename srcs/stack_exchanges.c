/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:28:36 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/25 14:28:37 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_list	*first;

	if (!(*(stack->b)))
		return ;
	first = *(stack->b);
	*(stack->b) = first->next;
	ft_lstadd_front(stack->a, first);
	
	printnumber(*(stack->a), *(stack->b));
}

void	pb(t_stack *stack)
{
	t_list	*first;

	if (!(*(stack->a)))
		return ;
	first = *(stack->a);
	*(stack->a) = first->next;
	ft_lstadd_front(stack->b, first);

	printnumber(*(stack->a), *(stack->b));
}

void	sa(t_stack *stack)
{
	int		size;
	t_list	*first;
	t_list	*second;

	if (!(*(stack->a)))
		return ;
	size = ft_lstsize(*(stack->a));
	if (size == 1)
		return ;
	first = *(stack->a);
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack->a = second;

	printnumber(*(stack->a), *(stack->b));
}

void	sb(t_stack *stack)
{
	int		size;
	t_list	*first;
	t_list	*second;

	if (!(*(stack->b)))
		return ;
	size = ft_lstsize(*(stack->b));
	if (size == 1)
		return ;
	first = *(stack->b);
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack->b = second;

	printnumber(*(stack->a), *(stack->b));
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
