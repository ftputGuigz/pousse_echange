/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:07:58 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/26 17:08:03 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_first_stack_elem(t_list *lst)
{
	int	content;

	content = *(int *)(lst->content);
	return (content);
}

int	is_sorted(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (*((int *)lst->content) > *((int *)lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*print_mov_and_jump(char *mov, t_list *lst)
{
	ft_putstr(mov);
	ft_putchar('\n');
	lst = lst->next->next;
	return (lst);
}

t_list	*print_mov_and_next(char *mov, t_list *lst)
{
	ft_putstr(mov);
	ft_putchar('\n');
	lst = lst->next;
	return (lst);
}

void	print_stack_output(t_stack *stack)
{
	t_list	*lst;

	lst = *(stack->output);
	while (lst)
	{
		if (lst->next && ((!ft_strcmp("sa", (char *)lst->content) && \
		!ft_strcmp("sb", (char *)lst->next->content)) || \
		(!ft_strcmp("sb", (char *)lst->content) && \
		!ft_strcmp("sa", (char *)lst->next->content))))
			lst = print_mov_and_jump("ss", lst);
		else if (lst->next && ((!ft_strcmp("ra", (char *)lst->content) && \
		!ft_strcmp("rb", (char *)lst->next->content)) || \
		(!ft_strcmp("rb", (char *)lst->content) && \
		!ft_strcmp("ra", (char *)lst->next->content))))
			lst = print_mov_and_jump("rr", lst);
		else if (lst->next && ((!ft_strcmp("rra", (char *)lst->content) && \
		!ft_strcmp("rrb", (char *)lst->next->content)) || \
		(!ft_strcmp("rrb", (char *)lst->content) && \
		!ft_strcmp("rra", (char *)lst->next->content))))
			lst = print_mov_and_jump("rrr", lst);
		else
			lst = print_mov_and_next((char *)lst->content, lst);
	}
}
