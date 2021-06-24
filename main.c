/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:56:10 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/23 18:55:24 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_buffer(char ***buf, char *str)
{
	static int i = 0;

	(*buf)[i++] = ft_strdup(str);
	//PROTEGER RETOUR
}

int	search_doublon(char **buf, char *str)
{
	int i = 0;

	while (buf[i])
	{
		if (!ft_strcmp(buf[i], str))
			return (1);
		i++;
	}
	return (0);
}

int	is_an_int(char *str)
{
	long nb;

	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	else
		return (1);
}

int	input_conformity(char **buf, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || search_doublon(buf, str) || !is_an_int(str))
			return (0);
		i++;
	}
	return (1);
}

void	init_stack_a(int nb, t_stack *stack)
{
	t_list	*new_elem;
	void	*content;

	content = (int *)malloc(sizeof(int));
	if (!content)
		return ;
	*((int *)content) = nb;
	new_elem = ft_lstnew(content);
	ft_lstadd_back(stack->a, new_elem);
}

void	register_element(char ***buf, char *str, t_stack *stack)
{
	int	number;

	add_to_buffer(buf, str);
	number = ft_atoi(str);
	init_stack_a(number, stack);
}

char **create_buffer(int ac)
{
	char	**buf;
	int		i;

	i = 0;
	buf = malloc(sizeof(char *) * ac);
	if (buf)
	{
		while (i < ac)
		{
			buf[i] = 0;
			i++;
		}
	}
	return(buf);
}

int	register_datas(int ac, char **av, t_stack *stack)
{
	int i;
	char **buf;

	buf = create_buffer(ac);
	if (!buf)
		return (1);
	i = 1;
	while (av[i])
	{
		if (!input_conformity(buf, av[i]))
			return (1);
		else
			register_element(&buf, av[i], stack);
		i++;
	}
	t_list *lst;

	lst = *(stack->a);
	while (lst)
	{
		printf("RESULT = %i\n", *((int *)lst->content));
		lst = lst->next;
	}
	free_double(buf);
	return (0);
}

void	initialize_stack(t_stack *stack)
{
	stack->a = (t_list **)malloc(sizeof(t_list *));
	stack->b = (t_list **)malloc(sizeof(t_list *));
	*(stack->a) = 0;
	*(stack->b) = 0;
}

int	main(int ac, char **av)
{
	int ret;
	t_stack stack;

	if (ac == 1)
		return (0);
	initialize_stack(&stack);
	ret = register_datas(ac, av, &stack);
	if (ret)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	//push_swap();
	return (0);
}
