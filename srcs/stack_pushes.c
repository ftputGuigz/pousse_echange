/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pushes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:55:13 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/29 14:55:16 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *stack)
{
	t_list	*first;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->b)))
		return (1);
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
		return (1);
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
