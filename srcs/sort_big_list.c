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

int	*search_median(t_stack *stack)
{
	t_list	*lst;
	int		*arr;
	int		*median;
	int		i;

	i = 0;
	lst = *(stack->a);
	arr = malloc(sizeof(int) * ft_lstsize(lst));
	if (!arr)
		return (NULL);
	while (lst)
	{
		arr[i++] = *((int *)lst->content);
		lst = lst->next;
	}
	ft_simplesort(arr, i);
	median = malloc(sizeof(int));
	if (!median)
	{
		free(arr);
		return (NULL);
	}
	*median = arr[ft_lstsize(*(stack->a)) / 2];
	free(arr);
	return (median);
}

void	under_median_goes_b(int median, t_stack *stack)
{
	int		last_number;
	t_list	*lst;

	lst = *(stack->a);
	last_number = *((int *)(ft_lstlast(lst)->content));
	while (*((int *)lst->content) != last_number)
	{
		if (*((int *)lst->content) < median)
			pb(stack);
		else
			ra(stack);
		lst = *(stack->a);
	}
	if (*((int *)lst->content) < median)
		pb(stack);
}

void	higher_median_goes_b(int median, t_stack *stack) //OPTIMISER !!!!! TROP DE CHEMINS
{
	int		last_number;
	t_list	*lst;

	lst = *(stack->a);
	last_number = *((int *)(ft_lstlast(lst)->content));
	while (*((int *)lst->content) != last_number)
	{
		if (*((int *)lst->content) > median)
			pb(stack);
		else
			ra(stack);
		lst = *(stack->a);
	}
	if (*((int *)lst->content) > median)
		pb(stack);
}

int	max_distance_to_exit(t_stack *stack)
{
	int		counter;
	t_list	*lst;

	counter = 0;
	lst = *(stack->b);
	while (lst && *((int *)lst->content) != stack->b_max)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

int	min_distance_to_exit(t_stack *stack)
{
	int		counter;
	t_list	*lst;

	counter = 0;
	lst = *(stack->b);
	while (lst && *((int *)lst->content) != stack->b_min)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

void	rotate_b_down(int moves, t_stack *stack)
{
	while (moves != 0)
	{
		moves--;
		rrb(stack);
	}
}

void	rotate_b_up(int moves, t_stack *stack)
{
	while (moves != 0)
	{
		moves--;
		rb(stack);
	}
}

void	pushback_to_a(t_stack *stack)
{
	int moves_max;
	int	moves_max_backward;
	int moves_min;
	int	moves_min_backward;
	int	size;

	if (!(*stack->b))
	 	return ;
	moves_max_backward = 0;
	moves_min_backward = 0;
	moves_max = max_distance_to_exit(stack);
	moves_min = min_distance_to_exit(stack);
	size = ft_lstsize(*(stack->b));
	if (moves_max > size / 2)
	{
		moves_max_backward = 1;
		moves_max = size - moves_max;
	}
	if (moves_min > size / 2)
	{
		moves_min_backward = 1;
		moves_min = size - moves_min;
	}
	if (moves_max <= moves_min)
	{
		if (moves_max_backward)
			rotate_b_down(moves_max, stack);
		else
			rotate_b_up(moves_max, stack);
	}
	else if (moves_min < moves)
	{
		if (moves_min_backward)
			rotate_b_down(moves_min, stack);
		else
			rotate_b_up(moves_min, stack);
	}
	if (!(*((int *)(*stack->b)->content) < *((int *)(*stack->a)->content)))
		ra(stack);
	pa(stack);
	pushback_to_a(stack);
}

int	sort_big_list(t_stack *stack)
{
	int	*median;
	
	median = search_median(stack);
	if (!median)
		return (0);
	under_median_goes_b(*median, stack);
	pushback_to_a(stack);
	higher_median_goes_b(*median, stack);
	pushback_to_a(stack);
	order_list(stack);
	free(median);
	return (1);
}