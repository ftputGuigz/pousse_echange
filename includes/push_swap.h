/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:05:12 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/23 14:55:42 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef	struct s_stack
{
	t_list **a;
	t_list **b;
}	t_stack;

void	initialize_stack(t_stack *stack);
int		register_datas(int ac, char **av, t_stack *stack);
void	free_stack_ptr(t_stack *stack);
void	del(void *content);
int		add_to_buffer(char ***buf, char *str);
int		input_conformity(char **buf, char *str);

#endif
