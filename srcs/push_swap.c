/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:43:36 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/25 14:44:17 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stack *stack)
{
	int	size;
	int	ret;

	ret = 1;
	size = ft_lstsize(*(stack->a));
	if (is_sorted(*(stack->a)) || size == 1)
		return (ret);
	if (size <= 3)
	{
		if (size == 3)
			ret = sort_mini_list(stack, 'a');
		order_list(stack);
	}
	if (size > 3 && size <= 6)
		sort_3_to_5(stack);
	if (size > 6)
		ret = sort_big_list(stack);
	print_stack_output(stack);
	return (ret);
}
