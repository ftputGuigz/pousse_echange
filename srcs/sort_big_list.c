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

int	*create_median_tab(int nb_elem, int *arr)
{
	int	*median;
	int	i;
	int	modulo;

	i = 0;
	modulo = nb_elem % 60;
	if (nb_elem / 60 == 0)
		median = malloc(sizeof(int));
	else
	{
		if (modulo != 0)
			modulo = 1;
		median = malloc(sizeof(int) * (nb_elem / 60 + modulo - 1));
	}
	if (!median)
		return (NULL);
	if (nb_elem / 60 < 2)
		*median = arr[nb_elem / 2];
	else
	{
		while (i != nb_elem / 60 + modulo - 1)
		{
			median[i] = arr[60 * (i + 1)];
			i++;
		}
	}
	return (median);
}

int	*search_median(t_stack *stack)
{
	t_list	*lst;
	int		size;
	int		*arr;
	int		*median;
	int		i;

	i = 0;
	lst = *(stack->a);
	size = ft_lstsize(lst);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (lst)
	{
		arr[i++] = *((int *)lst->content);
		lst = lst->next;
	}
	ft_simplesort(arr, i);
	median = create_median_tab(size, arr);
	if (!median)
	{
		free(arr);
		return (NULL);
	}
	free(arr);
	return (median);
}

void	first_under_median_goes_b(int oldmedian, int median, t_stack *stack)
{
	int		last_number;
	t_list	*lst;

	lst = *(stack->a);
	last_number = *((int *)(ft_lstlast(lst)->content));
	while (*((int *)lst->content) != last_number)
	{
		if (*((int *)lst->content) <= median
			&& *((int *)lst->content) > oldmedian)
			pb(stack);
		else
			ra(stack);
		lst = *(stack->a);
	}
	if (*((int *)lst->content) <= median
		&& *((int *)lst->content) > oldmedian)
		pb(stack);
}

void	under_median_goes_b(int oldmedian, int median, t_stack *stack)
{
	int		count;
	t_list	*lst;

	count = 0;
	lst = *(stack->a);
	while (*((int *)lst->content) != stack->a_min && count <= 60)
	{
		if (*((int *)lst->content) <= median
			&& *((int *)lst->content) > oldmedian)
		{
			count++;
			pb(stack);
		}
		else
			ra(stack);
		lst = *(stack->a);
	}
	if (*((int *)lst->content) <= median
		&& *((int *)lst->content) > oldmedian)
		pb(stack);
}

void	higher_median_goes_b(int median, t_stack *stack)
{
	t_list	*lst;

	lst = *(stack->a);
	while (*((int *)lst->content) != stack->a_min)
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

int	median_distance_to_exit(int median, t_stack *stack)
{
	int		counter;
	t_list	*lst;

	counter = 0;
	lst = *(stack->a);
	while (lst && *((int *)lst->content) != median)
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
	int	moves_max;
	int	moves_max_backward;
	int	moves_min;
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
	else if (moves_min < moves_max)
	{
		if (moves_min_backward)
			rotate_b_down(moves_min, stack);
		else
			rotate_b_up(moves_min, stack);
	}
	if (!(*((int *)(*(stack->b))->content) < *((int *)(*(stack->a))->content)))
		ra(stack);
	pa(stack);
	pushback_to_a(stack);
}

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

int	sort_big_list(t_stack *stack)
{
	int nb_elem;
	int modulo;
	int	*median;
	int	oldmedian;
	int i;
	int	first;

	i = 0;
	nb_elem = ft_lstsize(*(stack->a));
	modulo = nb_elem % 60;
	if (modulo != 0)
		modulo = 1;
	oldmedian = stack->a_min;
	median = search_median(stack);
	if (!median)
		return (0);
	first = 0;
	while (i != nb_elem / 60 + modulo - 1)
	{
		if (first == 0)
		{	
			first = 1;
			first_under_median_goes_b(oldmedian, median[i], stack);
		}
		else
			under_median_goes_b(oldmedian, median[i], stack);
		alignate_median(oldmedian, stack);
		pushback_to_a(stack);
		oldmedian = median[i++];
	}
	if (i == 0)
	{
		first_under_median_goes_b(oldmedian, median[i], stack);
		alignate_median(oldmedian, stack);
		pushback_to_a(stack);
		oldmedian = median[i++];
	}
	higher_median_goes_b(median[i - 1], stack);
	alignate_median(oldmedian, stack);
	pushback_to_a(stack);
	order_list(stack);
	free(median);
	return (1);
}
