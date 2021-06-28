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

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%i\n", *((int *)(lst->content)));
		lst = lst->next;
	}
}

void	printnumber(t_list *a, t_list *b)
{
	t_list	*tmpa;
	t_list	*tmpb;

	tmpa = a;
	tmpb = b;
	printf("\e[H\e[2J");
	printf("%11c   %-11c\n", 'a', 'b');
	while (a || b)
	{
		if (a)
		{
			printf("%11d | ", *((int *)a->content));
			a = a->next;
		}
		else
			printf("%11s | ", "");
		if (b)
		{
			printf("%-11d", *((int *)b->content));
			b = b->next;
		}
		printf("\n");
	}
	a = tmpa;
	b = tmpb;
	sleep(1);
}

void	push_swap(t_stack *stack)
{
 	printnumber(*(stack->a), *(stack->b));
	pb(stack);
	printnumber(*(stack->a), *(stack->b));
	pb(stack);
	printnumber(*(stack->a), *(stack->b));
	pb(stack);
	printnumber(*(stack->a), *(stack->b));
	pb(stack);
	printnumber(*(stack->a), *(stack->b));
	pb(stack);
	printnumber(*(stack->a), *(stack->b));
	pb(stack);
	printnumber(*(stack->a), *(stack->b));
	pa(stack);
	printnumber(*(stack->a), *(stack->b));
	pa(stack);
	printnumber(*(stack->a), *(stack->b));
	sa(stack);
	printnumber(*(stack->a), *(stack->b));
	rrr(stack);
	printnumber(*(stack->a), *(stack->b));
}
