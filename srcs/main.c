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
	ret = push_swap(&stack);
	if (!ret)
		ft_putstr_fd("Error\n", 2);
	free_stack_ptr(&stack);
	return (0);
}
