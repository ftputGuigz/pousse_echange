/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list_median2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:17:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/29 13:17:08 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alignate_median(int median, t_stack *stack)
{
	int	moves;

	moves = median_distance_to_exit(median, stack);
	if (moves > ft_lstsize(*stack->a) / 2)
	{
		moves = ft_lstsize(*stack->a) - moves;
		while (moves != 0)
		{
			if (!rra(stack))
				return (0);
			moves--;
		}
	}
	else
	{
		while (moves != 0)
		{
			if (!ra(stack))
				return (0);
			moves--;
		}
	}
	return (1);
}
