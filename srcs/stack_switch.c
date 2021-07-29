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

void	switch_first_second(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

int	sa(t_stack *stack)
{
	int		size;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->a)))
		return (1);
	size = ft_lstsize(*(stack->a));
	if (size == 1)
		return (1);
	switch_first_second(stack->a);
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
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->b)))
		return (1);
	size = ft_lstsize(*(stack->b));
	if (size == 1)
		return (1);
	switch_first_second(stack->b);
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

int	ss(t_stack *stack)
{
	if (!sa(stack))
		return (0);
	if (!sb(stack))
		return (0);
	return (1);
}
