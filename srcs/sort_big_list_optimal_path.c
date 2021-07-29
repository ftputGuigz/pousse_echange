/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:26:02 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/26 18:26:04 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_distance_to_exit(t_stack *stack)
{
	int		counter;
	t_list	*lst;

	counter = 0;
	lst = *(stack->b);
	while (lst && *((int *)lst->content) != stack->b_max)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

int	median_distance_to_exit(int median, t_stack *stack)
{
	int		counter;
	t_list	*lst;

	counter = 0;
	lst = *(stack->a);
	while (lst && *((int *)lst->content) != median)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

int	min_distance_to_exit(t_stack *stack)
{
	int		counter;
	t_list	*lst;

	counter = 0;
	lst = *(stack->b);
	while (lst && *((int *)lst->content) != stack->b_min)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

int	rotate_b_down(int moves, t_stack *stack)
{
	while (moves != 0)
	{
		moves--;
		if (!rrb(stack))
			return (0);
	}
	return (1);
}

int	rotate_b_up(int moves, t_stack *stack)
{
	while (moves != 0)
	{
		moves--;
		if (!rb(stack))
			return (0);
	}
	return (1);
}
