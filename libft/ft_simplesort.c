/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:46:04 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/06 10:46:06 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_simplesort(int *tab, int size)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 1;
	while (j <= (size - 1))
	{
		if (tab[j] < tab[i])
		{
			a = tab[j];
			tab[j] = tab[i];
			tab[i] = a;
			i = 0;
			j = 1;
		}
		else
		{
			i++;
			j++;
		}
	}
}
