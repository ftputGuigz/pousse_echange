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

int	alignate_median_push_elem(int *olmed, int **med, int *i, t_stack *stack)
{
	if (!alignate_median(*olmed, stack))
		return (0);
	if (!pushback_to_a(stack))
		return (0);
	*olmed = (*med)[*i];
	(*i)++;
	return (1);
}

int	loop_median(int *oldmedian, int **median, int *i, t_stack *stack)
{
	if (!under_median_goes_b(*oldmedian, (*median)[*i], stack))
		return (0);
	if (!alignate_median_push_elem(oldmedian, median, i, stack))
		return (0);
	return (1);
}

int	last_median(int	oldmedian, int last_median, t_stack *stack)
{
	if (!higher_median_goes_b(last_median, stack))
		return (0);
	if (!alignate_median(oldmedian, stack))
		return (0);
	if (!pushback_to_a(stack))
		return (0);
	if (!order_list(stack))
		return (0);
	return (1);
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
		if (!loop_median(&oldmedian, &median, &i, stack))
			return (0);
	if (!last_median(oldmedian, median[i - 1], stack))
	{
		free(median);
		return (0);
	}
	free(median);
	return (1);
}
