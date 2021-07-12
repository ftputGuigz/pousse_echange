/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:18:24 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/25 15:18:27 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_list	*first;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->a)))
		return ;
	first = *(stack->a);
	*(stack->a) = first->next;
	first->next = 0;
	ft_lstadd_back(stack->a, first);
	content = ft_strdup("ra");
	new_operation = ft_lstnew(content);
	ft_lstadd_back(stack->output, new_operation);

	moves++;
	printnumber(*(stack->a), *(stack->b));
}

void	rb(t_stack *stack)
{
	t_list	*first;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->b)))
		return ;
	first = *(stack->b);
	*(stack->b) = first->next;
	first->next = 0;
	ft_lstadd_back(stack->b, first);
	content = ft_strdup("rb");
	new_operation = ft_lstnew(content);
	ft_lstadd_back(stack->output, new_operation);

	moves++;
	printnumber(*(stack->a), *(stack->b));
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	moves--;
}
