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

int	init_variables(int nb_elem, int *oldmedian, int **median, t_stack *stack)
{
	int	modulo;

	modulo = nb_elem % 60;
	if (modulo != 0)
		modulo = 1;
	*oldmedian = stack->a_min;
	*median = search_median(stack);
	return (modulo);
}

void	alignate_median_push_elem(int *olmed, int **med, int *i, t_stack *stack)
{
	alignate_median(*olmed, stack);
	pushback_to_a(stack);
	*olmed = (*med)[*i];
	(*i)++;
}

int	sort_big_list(t_stack *stack)
{
	int	nb_elem;
	int	modulo;
	int	*median;
	int	oldmedian;
	int	i;

	i = 0;
	nb_elem = ft_lstsize(*(stack->a));
	modulo = init_variables(nb_elem, &oldmedian, &median, stack);
	if (!median)
		return (0);
	while (i == 0 || i < nb_elem / 60 + modulo - 1)
	{
		under_median_goes_b(oldmedian, median[i], stack);
		alignate_median_push_elem(&oldmedian, &median, &i, stack);
	}
	higher_median_goes_b(median[i - 1], stack);
	alignate_median(oldmedian, stack);
	pushback_to_a(stack);
	order_list(stack);
	free(median);
	return (1);
}
