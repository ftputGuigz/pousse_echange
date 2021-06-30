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

int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (*((int *)lst->content) > *((int *)lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	push_swap(t_stack *stack)
{
	int	size;

	size = ft_lstsize(*(stack->a));
	if (is_sorted(*(stack->a)) || size == 1)
		return ;
	printnumber(*stack->a, *stack->b);
	if (size <= 3)
		sort_mini_list(stack, 'a');
}
