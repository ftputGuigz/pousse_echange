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

char	*register_line(void)
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
		if (!line)
			return (line);
		line[size] = buf[0];
		line[size + 1] = '\0';
		size++;
		if (buf[0] == '\n')
			break ;
		ret = read(STDIN_FILENO, buf, 1);
	}
	if (ret == -1)
		clean_free(&line);
	return (line);
}

int	applicate_move_to_stack(char *line, t_stack *stack)
{
	if (!ft_strcmp(line, "sa\n"))
		return (sa(stack));
	else if (!ft_strcmp(line, "sb\n"))
		return (sb(stack));
	else if (!ft_strcmp(line, "ss\n"))
		return (ss(stack));
	else if (!ft_strcmp(line, "pa\n"))
		return (pa(stack));
	else if (!ft_strcmp(line, "pb\n"))
		return (pb(stack));
	else if (!ft_strcmp(line, "ra\n"))
		return (ra(stack));
	else if (!ft_strcmp(line, "rb\n"))
		return (rb(stack));
	else if (!ft_strcmp(line, "rr\n"))
		return (rr(stack));
	else if (!ft_strcmp(line, "rra\n"))
		return (rra(stack));
	else if (!ft_strcmp(line, "rrb\n"))
		return (rrb(stack));
	else if (!ft_strcmp(line, "rrr\n"))
		return (rrr(stack));
	else
		ft_putstr_fd("Error\n", 2);
	return (1);
}

int	execute_moves(t_stack *stack)
{
	int		ret;
	char	*line;

	line = register_line();
	if (!line)
		return (0);
	while (line && ft_strcmp(line, "\n"))
	{
		ret = applicate_move_to_stack(line, stack);
		clean_free(&line);
		if (!ret)
			return (0);
		line = register_line();
	}
	clean_free(&line);
	return (1);
}

void	check_if_pile_a_sorted(t_list *pile_a, t_list *pile_b)
{
	if (is_sorted(pile_a) && !pile_b)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 1)
		return (0);
	if (!initialize_stack(&stack) || !register_datas(av, &stack))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack_ptr(&stack);
		return (0);
	}
	if (!execute_moves(&stack))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack_ptr(&stack);
		return (0);
	}
	check_if_pile_a_sorted(*(stack.a), *(stack.b));
	free_stack_ptr(&stack);
	return (0);
}
