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

	if (!(*(stack->a)))
		return ;
	first = *(stack->a);
	*(stack->a) = first->next;
	first->next = 0;
	ft_lstadd_back(stack->a, first);

	moves++;
	printnumber(*(stack->a), *(stack->b));

	ft_putstr("ra\n");
}

void	rb(t_stack *stack)
{
	t_list	*first;

	if (!(*(stack->b)))
		return ;
	first = *(stack->b);
	*(stack->b) = first->next;
	first->next = 0;
	ft_lstadd_back(stack->b, first);

	moves++;
	printnumber(*(stack->a), *(stack->b));

	ft_putstr("rb\n");
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	moves--;
}
