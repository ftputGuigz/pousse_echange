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

typedef struct s_moves
{
	int	max;
	int	max_backward;
	int	min;
	int	min_backward;
	int	size;
}	t_moves;

int	flag_new_moves(int *flag, int size, int moves)
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

void	init_moves(t_moves *moves, t_stack *stack)
{
	moves->max_backward = 0;
	moves->min_backward = 0;
	moves->max = max_distance_to_exit(stack);
	moves->min = min_distance_to_exit(stack);
	moves->size = ft_lstsize(*(stack->b));
}

int	pushback_to_a(t_stack *stack)
{
	t_moves	moves;

	if (!(*stack->b))
		return (1);
	init_moves(&moves, stack);
	if (moves.max > moves.size / 2)
		moves.max = flag_new_moves(&moves.max_backward, moves.size, moves.max);
	if (moves.min > moves.size / 2)
		moves.min = flag_new_moves(&moves.min_backward, moves.size, moves.min);
	if (moves.max <= moves.min)
		if (!move_max_or_min(moves.max_backward, moves.max, stack))
			return (0);
	if (moves.min < moves.max)
		if (!move_max_or_min(moves.min_backward, moves.min, stack))
			return (0);
	if (!(*((int *)(*(stack->b))->content) < *((int *)(*(stack->a))->content)))
		if (!ra(stack))
			return (0);
	if (!pa(stack))
		return (0);
	return (pushback_to_a(stack));
}
