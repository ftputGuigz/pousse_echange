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

int	sort_big_list(t_stack *stack)
{
	int	*median;
	
	median = search_median(stack);
	if (!median)
		return (0);
	printf("MEDIAN = %d\n", *median);
	under_median()
	free(median);
	return (1);
}