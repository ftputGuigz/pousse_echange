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

static void	move_max_or_min(int flag, int moves, t_stack *stack)
{
	if (flag)
		rotate_b_down(moves, stack);
	else
		rotate_b_up(moves, stack);
}

void	pushback_to_a(t_stack *stack)
{
	int	moves_max;
	int	max_backward;
	int	moves_min;
	int	min_backward;
	int	size;

	if (!(*stack->b))
		return ;
	init_pushback_flags(&max_backward, &min_backward);
	size = init_size_and_moves(&moves_max, &moves_min, stack);
	if (moves_max > size / 2)
		moves_max = set_flag_recalculate_moves(&max_backward, size, moves_max);
	if (moves_min > size / 2)
		moves_min = set_flag_recalculate_moves(&min_backward, size, moves_min);
	if (moves_max <= moves_min)
		move_max_or_min(max_backward, moves_max, stack);
	else if (moves_min < moves_max)
		move_max_or_min(min_backward, moves_min, stack);
	if (!(*((int *)(*(stack->b))->content) < *((int *)(*(stack->a))->content)))
		ra(stack);
	pa(stack);
	pushback_to_a(stack);
}
