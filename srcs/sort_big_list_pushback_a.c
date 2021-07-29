/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list_pushback_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:06:29 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/27 11:06:31 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_size_and_moves(int *moves_max, int *moves_min, t_stack *stack)
{
	int	size;

	*moves_max = max_distance_to_exit(stack);
	*moves_min = min_distance_to_exit(stack);
	size = ft_lstsize(*(stack->b));
	return (size);
}

static void	init_pushback_flags(int *mmb, int *mminb)
{
	*mmb = 0;
	*mminb = 0;
}

int	set_flag_recalculate_moves(int *flag, int size, int moves)
{
	*flag = 1;
	moves = size - moves;
	return (moves);
}

static int	move_max_or_min(int flag, int moves, t_stack *stack)
{
	if (flag)
	{
		if (!rotate_b_down(moves, stack))
			return (0);
	}
	else
	{	
		if (!rotate_b_up(moves, stack))
			return (0);
	}
	return (1);
}

int	pushback_to_a(t_stack *stack)
{
	int	moves_max;
	int	max_backward;
	int	moves_min;
	int	min_backward;
	int	size;

	if (!(*stack->b))
		return (1);
	init_pushback_flags(&max_backward, &min_backward);
	size = init_size_and_moves(&moves_max, &moves_min, stack);
	if (moves_max > size / 2)
		moves_max = set_flag_recalculate_moves(&max_backward, size, moves_max);
	if (moves_min > size / 2)
		moves_min = set_flag_recalculate_moves(&min_backward, size, moves_min);
	if (moves_max <= moves_min)
	{
		if (!move_max_or_min(max_backward, moves_max, stack))
			return (0);
	}
	else if (moves_min < moves_max)
	{
		if (!move_max_or_min(min_backward, moves_min, stack))
			return (0);
	}
	if (!(*((int *)(*(stack->b))->content) < *((int *)(*(stack->a))->content)))
		if (!ra(stack))
			return (0);
	if (!pa(stack))
		return (0);
	return (pushback_to_a(stack));
}
