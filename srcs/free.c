/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:24:52 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/25 12:24:54 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_ptr(t_stack *stack)
{
	ft_lstclear(stack->a, del);
	ft_lstclear(stack->b, del);
	ft_lstclear(stack->output, del);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->output)
		free(stack->output);
}

void	del(void *content)
{
	free(content);
	content = NULL;
}
