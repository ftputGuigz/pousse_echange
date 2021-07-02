/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_conformity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:25:03 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/25 12:25:04 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_buffer(int ***buf, char *str)
{
	static int	i = 0;

	(*buf)[i] = malloc(sizeof(int));
	if (!((*buf)[i]))
		return (0);
	*((*buf)[i]) = (int)ft_atoi(str);
	i++;
	return (1);
}

int	search_doublon(int **buf, char *str)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (*(buf[i]) == ft_atoi(str))
			return (1);
		i++;
	}
	return (0);
}

int	is_an_int(char *str)
{
	long	nb;

	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	else
		return (1);
}

int	is_valid_digit(char *str)
{
	int	i;

	if (str[0] != '-' && !ft_isdigit(str[0]))
		return (0);
	if (str[0] == '-' && (!str[1] || !ft_isdigit(str[1])))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	input_conformity(int **buf, char *str)
{
	if (!is_valid_digit(str) || search_doublon(buf, str) || !is_an_int(str))
		return (0);
	else
		return (1);
}
