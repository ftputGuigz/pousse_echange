/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:25:08 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/25 12:25:11 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	register_element(int ***buf, char *str, t_stack *stack)
{
	int	number;

	if (!(add_to_buffer(buf, str)))
		return (0);
	number = ft_atoi(str);
	if (!(init_stack_a(number, stack)))
		return (0);
	return (1);
}

void	count_malloc_elem(int *size, char *str)
{
	char	**temp;

	temp = ft_split(str, ' ');
	*(size) += ft_dbstrlen(temp);
	free_double(temp);
}

int	**create_buffer(char **av)
{
	int		**buf;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 1;
	size = 0;
	while (av[j])
		count_malloc_elem(&size, av[j++]);
	if (!size)
		buf = NULL;
	else
		buf = (int **)malloc(sizeof(int *) * (size + 1));
	if (buf)
	{
		while (i <= size)
		{
			buf[i] = NULL;
			i++;
		}
	}
	return (buf);
}

int	register_input(char *elem, int ***buf, t_stack *stack)
{
	int		j;
	int		ret;
	char	**arr;

	arr = ft_split(elem, ' ');
	j = 0;
	while (arr[j])
	{
		if (!input_conformity(*buf, arr[j]))
			ret = 0;
		else
			ret = register_element(buf, arr[j], stack);
		if (!ret)
		{
			free_double(arr);
			free_double_int(*buf);
			ft_lstclear(stack->a, del);
			return (0);
		}
		j++;
	}
	free_double(arr);
	return (1);
}

int	register_datas(char **av, t_stack *stack)
{
	int		i;
	int		**buf;
	int		ret;

	buf = create_buffer(av);
	if (!buf)
		return (0);
	i = 1;
	while (av[i])
	{	
		ret = register_input(av[i++], &buf, stack);
		if (!ret)
			return (0);
	}
	free_double_int(buf);
	stacks_min_max(stack);
	return (1);
}
