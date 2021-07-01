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

void	initialize_stack(t_stack *stack)
{
	stack->a_min = 0;
	stack->a_max = 0;
	stack->b_min = 0;
	stack->b_max = 0;
	stack->a = (t_list **)malloc(sizeof(t_list *));
	stack->b = (t_list **)malloc(sizeof(t_list *));
	*(stack->a) = 0;
	*(stack->b) = 0;
}
