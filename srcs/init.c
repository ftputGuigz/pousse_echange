/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:24:58 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/25 12:24:59 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_stack(t_stack *stack)
{
	stack->a_min = 0;
	stack->a_max = 0;
	stack->b_min = 0;
	stack->b_max = 0;
	stack->a = (t_list **)malloc(sizeof(t_list *));
	stack->b = (t_list **)malloc(sizeof(t_list *));
	stack->output = (t_list **)malloc(sizeof(t_list *));
	if (!(stack->a) || !(stack->b) || !(stack->output))
	{
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
		if (stack->output)
			free(stack->output);
		return (0);
	}
	*(stack->a) = 0;
	*(stack->b) = 0;
	*(stack->output) = 0;
	return (1);
}

int	init_stack_a(int nb, t_stack *stack)
{
	t_list	*new_elem;
	void	*content;

	content = (int *)malloc(sizeof(int));
	if (!content)
		return (0);
	*((int *)content) = nb;
	new_elem = ft_lstnew(content);
	if (!new_elem)
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(stack->a, new_elem);
	return (1);
}
