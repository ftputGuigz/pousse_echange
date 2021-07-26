/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:36:48 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/30 16:37:02 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushback_to_a(t_stack *stack)
{
	int	moves_max;
	int	moves_max_backward;
	int	moves_min;
	int	moves_min_backward;
	int	size;

	if (!(*stack->b))
		return ;
	moves_max_backward = 0;
	moves_min_backward = 0;
	moves_max = max_distance_to_exit(stack);
	moves_min = min_distance_to_exit(stack);
	size = ft_lstsize(*(stack->b));
	if (moves_max > size / 2)
	{
		moves_max_backward = 1;
		moves_max = size - moves_max;
	}
	if (moves_min > size / 2)
	{
		moves_min_backward = 1;
		moves_min = size - moves_min;
	}
	if (moves_max <= moves_min)
	{
		if (moves_max_backward)
			rotate_b_down(moves_max, stack);
		else
			rotate_b_up(moves_max, stack);
	}
	else if (moves_min < moves_max)
	{
		if (moves_min_backward)
			rotate_b_down(moves_min, stack);
		else
			rotate_b_up(moves_min, stack);
	}
	if (!(*((int *)(*(stack->b))->content) < *((int *)(*(stack->a))->content)))
		ra(stack);
	pa(stack);
	pushback_to_a(stack);
}

void	alignate_median(int median, t_stack *stack)
{
	int	moves;

	moves = median_distance_to_exit(median, stack);
	if (moves > ft_lstsize(*stack->a) / 2)
	{
		moves = ft_lstsize(*stack->a) - moves;
		while (moves != 0)
		{
			rra(stack);
			moves--;
		}
	}
	else
	{
		while (moves != 0)
		{
			ra(stack);
			moves--;
		}
	}
}

int	sort_big_list(t_stack *stack)
{
	int nb_elem;
	int modulo;
	int	*median;
	int	oldmedian;
	int i;
	int	first;

	i = 0;
	nb_elem = ft_lstsize(*(stack->a));
	modulo = nb_elem % 60;
	if (modulo != 0)
		modulo = 1;
	oldmedian = stack->a_min;
	median = search_median(stack);
	if (!median)
		return (0);
	first = 0;
	while (i != nb_elem / 60 + modulo - 1)
	{
		if (first == 0)
		{	
			first = 1;
			first_under_median_goes_b(oldmedian, median[i], stack);
		}
		else
			under_median_goes_b(oldmedian, median[i], stack);
		alignate_median(oldmedian, stack);
		pushback_to_a(stack);
		oldmedian = median[i++];
	}
	if (i == 0)
	{
		first_under_median_goes_b(oldmedian, median[i], stack);
		alignate_median(oldmedian, stack);
		pushback_to_a(stack);
		oldmedian = median[i++];
	}
	higher_median_goes_b(median[i - 1], stack);
	alignate_median(oldmedian, stack);
	pushback_to_a(stack);
	order_list(stack);
	free(median);
	return (1);
}
