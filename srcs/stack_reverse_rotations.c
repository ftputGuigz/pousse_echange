/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:42:33 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/25 15:42:34 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_penultimate(t_list *lst)
{
	if (!lst || !(lst->next))
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	rra(t_stack *stack)
{
	int		size;
	t_list	*penultimate;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->a)))
		return (1);
	size = ft_lstsize(*(stack->a));
	if (size == 1)
		return (1);
	penultimate = ft_lst_penultimate(*(stack->a));
	ft_lstadd_front(stack->a, penultimate->next);
	penultimate->next = NULL;
	content = ft_strdup("rra");
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

int	rrb(t_stack *stack)
{
	int		size;
	t_list	*penultimate;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->b)))
		return (1);
	size = ft_lstsize(*(stack->b));
	if (size == 1)
		return (1);
	penultimate = ft_lst_penultimate(*(stack->b));
	ft_lstadd_front(stack->b, penultimate->next);
	penultimate->next = NULL;
	content = ft_strdup("rrb");
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

int	rrr(t_stack *stack)
{
	if (!rra(stack))
		return (0);
	if (!rrb(stack))
		return (0);
	return (1);
}
