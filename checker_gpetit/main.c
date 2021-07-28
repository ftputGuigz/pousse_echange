/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:09:00 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/27 17:09:12 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*register_line()
{
	char	*line;
	char	buf[1];
	int		size;
	int		ret;

	size = 0;
	line = NULL;
	ret = read(STDIN_FILENO, buf, 1);
	while (ret)
	{
		line = ft_realloc(line, size + 2);
		line[size + 1] = '\0';
		line[size++] = buf[0];
		if (buf[0] == '\n')
			break ;
		read(STDIN_FILENO, buf, 1);
	}
	return (line);
}

void	applicate_move_to_stack(char *line, t_stack *stack)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(stack);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stack);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stack);
	else if (!ft_strcmp(line, "pa\n"))
		pa(stack);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stack);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stack);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stack);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stack);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stack);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stack);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stack);
	else
		ft_putstr_fd("Error\n", 2);
}

void	execute_moves(t_stack *stack)
{
	char	*line;

	line = register_line();
	while (ft_strcmp(line, "\n"))
	{
		applicate_move_to_stack(line, stack);
		clean_free(&line);
		line = register_line();
	}
	clean_free(&line);
}

int	main(int ac, char **av)
{
	int		ret;
	t_stack	stack;

	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	initialize_stack(&stack);
	ret = register_datas(av, &stack);
	if (!ret)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack_ptr(&stack);
		return (0);
	}
	execute_moves(&stack);
	if (is_sorted(*(stack.a)))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	free_stack_ptr(&stack);
	return (0);
}