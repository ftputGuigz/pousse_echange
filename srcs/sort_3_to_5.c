/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:11:49 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/26 17:11:52 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	locate_distance_to_placement(t_stack *stack)
{
	int		d;
	int		distance;
	int		first;
	int		second;
	t_list	*lst;

	distance = 1;
	d = get_first_stack_elem(*(stack->b));
	if (d < stack->a_min)
		return (locate_min(stack, 'a'));
	if (d > stack->a_max)
		return (locate_max(stack, 'a'));
	lst = *(stack->a);
	first = *((int *)lst->content);
	second = *((int *)lst->next->content);
	while ((!(d > first && d < second) && lst->next))
	{
		lst = lst->next;
		first = *((int *)lst->content);
		if (lst->next)
			second = *((int *)(lst->next->content));
		distance++;
	}
	return (distance);
}

int	inject_b_in_a_2(int *mvmt, int size, t_stack *stack)
{
	if (*mvmt <= size / 2)
	{	
		while (*mvmt)
		{
			if (!ra(stack))
				return (0);
			(*mvmt)--;
		}
	}
	if (*mvmt > size / 2)
	{
		*mvmt = size - *mvmt;
		while (*mvmt)
		{
			if (!rra(stack))
				return (0);
			(*mvmt)--;
		}
	}
	return (1);
}

int	inject_b_in_a(t_stack *stack)
{
	int	mvmt;
	int	size;

	mvmt = 0;
	while (*(stack->b))
	{
		mvmt = locate_distance_to_placement(stack);
		size = ft_lstsize(*(stack->a));
		if (!inject_b_in_a_2(&mvmt, size, stack))
			return (0);
		if (*(stack->b))
			if (!pa(stack))
				return (0);
	}
	return (1);
}

int	order_list(t_stack *stack)
{
	int	position;
	int	size;

	position = locate_min(stack, 'a');
	size = ft_lstsize(*(stack->a));
	if (position && position <= size / 2)
	{
		while (position)
		{
			if (!ra(stack))
				return (0);
			position--;
		}
	}
	else if (position && position > size / 2)
	{
		position = size - position;
		while (position)
		{
			if (!rra(stack))
				return (0);
			position--;
		}
	}
	return (1);
}

int	sort_3_to_5(t_stack *stack)
{
	while (ft_lstsize(*(stack->a)) != 3)
		if (!pb(stack))
			return (0);
	if (!sort_mini_list(stack, 'a'))
		return (0);
	if (!inject_b_in_a(stack))
		return (0);
	if (!order_list(stack))
		return (0);
	return (1);
}
