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
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->b)))
		return ;
	first = *(stack->b);
	*(stack->b) = first->next;
	ft_lstadd_front(stack->a, first);
	stacks_min_max(stack);
	content = ft_strdup("pa");
	new_operation = ft_lstnew(content);
	ft_lstadd_back(stack->output, new_operation);
}

void	pb(t_stack *stack)
{
	t_list	*first;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->a)))
		return ;
	first = *(stack->a);
	*(stack->a) = first->next;
	ft_lstadd_front(stack->b, first);
	stacks_min_max(stack);
	content = ft_strdup("pb");
	new_operation = ft_lstnew(content);
	ft_lstadd_back(stack->output, new_operation);
}

void	sa(t_stack *stack)
{
	int		size;
	t_list	*first;
	t_list	*second;
	t_list	*new_operation;
	void	*content;

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
	content = ft_strdup("sa");
	new_operation = ft_lstnew(content);
	ft_lstadd_back(stack->output, new_operation);
}

void	sb(t_stack *stack)
{
	int		size;
	t_list	*first;
	t_list	*second;
	t_list	*new_operation;
	void	*content;

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
	content = ft_strdup("sb");
	new_operation = ft_lstnew(content);
	ft_lstadd_back(stack->output, new_operation);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
