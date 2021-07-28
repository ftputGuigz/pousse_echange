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

int	pa(t_stack *stack)
{
	t_list	*first;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->b)))
		return (0);
	first = *(stack->b);
	*(stack->b) = first->next;
	ft_lstadd_front(stack->a, first);
	stacks_min_max(stack);
	content = ft_strdup("pa");
	if (!content)
		return (0);
	new_operation = ft_lstnew(content);
	if (!new_operation)
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(stack->output, new_operation);
	return (1);
}

int	pb(t_stack *stack)
{
	t_list	*first;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->a)))
		return (0);
	first = *(stack->a);
	*(stack->a) = first->next;
	ft_lstadd_front(stack->b, first);
	stacks_min_max(stack);
	content = ft_strdup("pb");
	if (!content)
		return (0);
	new_operation = ft_lstnew(content);
	if (!new_operation)
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(stack->output, new_operation);
	return (1);
}

int	sa(t_stack *stack)
{
	int		size;
	t_list	*first;
	t_list	*second;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->a)))
		return (0);
	size = ft_lstsize(*(stack->a));
	if (size == 1)
		return (1);
	first = *(stack->a);
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack->a = second;
	content = ft_strdup("sa");
	if (!content)
		return (0);
	new_operation = ft_lstnew(content);
	if (!new_operation)
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(stack->output, new_operation);
	return (1);
}

int	sb(t_stack *stack)
{
	int		size;
	t_list	*first;
	t_list	*second;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->b)))
		return (0);
	size = ft_lstsize(*(stack->b));
	if (size == 1)
		return (1);
	first = *(stack->b);
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack->b = second;
	content = ft_strdup("sb");
	if (!content)
		return (0);
	new_operation = ft_lstnew(content);
	if (!new_operation)
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(stack->output, new_operation);
	return (1);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
