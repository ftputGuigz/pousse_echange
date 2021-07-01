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

void	inject_b_in_a(t_stack *stack)
{
	t_list *lst;
	int	mvmt;
	int first;
	int second;
	int d;

	mvmt = 0;
	while (*(stack->b))
	{
		d = *(int *)((*(stack->b))->content);
		lst = *(stack->a);
		first = *((int *)lst->content);
		second = *((int *)lst->next->content);
		while ((!(d > first && d < second) && first != stack->a_min) && lst->next)
		{
			lst = lst->next;
			first = *((int *)lst->content);
			if (lst->next)
				second = *((int *)(lst->next->content));
			mvmt++;
		}
		if (d > first && d < second)
			mvmt++;
		int size = ft_lstsize(*(stack->a));
		printf("size = %d\nmvmt = %d\n", size, mvmt);
		if (mvmt <= size / 2)
		{	
			while (mvmt)
			{
				ra(stack);
				mvmt--;
			}
		}
		if (mvmt > size / 2)
		{
			mvmt = size - mvmt;
			while (mvmt)
			{
				rra(stack);
				mvmt--;
			}
		}
		if (*(stack->b))
			pa(stack);
	}
}

void	sort_3_to_5(t_stack *stack)
{
	int	position;
	int	size;

	while (ft_lstsize(*(stack->a)) != 3)
		pb(stack);
	sort_mini_list(stack, 'a');
	inject_b_in_a(stack);
	position = locate_min(stack);
	size = ft_lstsize(*(stack->a));
	if (!position)
		return ;
	if (position <= size / 2)
	{
		while (position)
		{
			ra(stack);
			position--;
		}
	}
	if (position > size / 2)
	{
		position = size - position;
		while (position)
		{
			rra(stack);
			position--;
		}
	}
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
	else if (size > 3 && size <= 5)
		sort_3_to_5(stack);
	printf("MOVES = [%d]\n", moves);
}
