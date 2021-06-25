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

void	rra(t_stack *stack)
{
	int		size;
	t_list	*penultimate;
	t_list	*last;

	if (!(*(stack->a)))
		return ;
	size = ft_lstsize(*(stack->a));
	if (size == 1)
		return ;
	last = ft_lstlast(*(stack->a));
	penultimate = ft_lst_penultimate(*(stack->a));
	penultimate->next = NULL;
	ft_lstadd_front(stack->a, last);
}

void	rrb(t_stack *stack)
{
	int		size;
	t_list	*penultimate;
	t_list	*last;

	if (!(*(stack->b)))
		return ;
	size = ft_lstsize(*(stack->a));
	if (size == 1)
		return ;
	last = ft_lstlast(*(stack->b));
	penultimate = ft_lst_penultimate(*(stack->b));
	penultimate->next = NULL;
	ft_lstadd_front(stack->b, last);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
