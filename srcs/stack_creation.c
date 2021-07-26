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

int	init_stack_a(int nb, t_stack *stack)
{
	t_list	*new_elem;
	void	*content;

	content = (int *)malloc(sizeof(int));
	if (!content)
		return (0);
	*((int *)content) = nb;
	new_elem = ft_lstnew(content);
	if (!new_elem)
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(stack->a, new_elem);
	return (1);
}

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

int	**create_buffer(char **av)
{
	int 	**buf;
	int		i;
	int		j;
	int		size;
	char	**temp;

	i = 0;
	j = 1;
	size = 0;
	while (av[j])
	{
		temp = ft_split(av[j], ' ');
		size += ft_dbstrlen(temp);
		free_double(temp);
		j++;
	}
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

int	register_datas(int ac, char **av, t_stack *stack)
{
	int		i;
	int		j;
	int		ret;
	int		**buf;
	char	**arr;

	(void)ac;
	buf = create_buffer(av);
	if (!buf)
		return (0);
	i = 1;
	while (av[i])
	{
		arr = ft_split(av[i], ' ');
		j = 0;
		while (arr[j])
		{
			if (!input_conformity(buf, arr[j]))
				ret = 0;
			else
				ret = register_element(&buf, arr[j], stack);
			if (!ret)
			{
				free_double_int(buf);
				ft_lstclear(stack->a, del);
				return (0);
			}
			j++;
		}
		free_double(arr);
		i++;
	}
	free_double_int(buf);
	stacks_min_max(stack);
	return (1);
}
