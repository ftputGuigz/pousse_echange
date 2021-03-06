/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:05:54 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/02 12:05:58 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_double_int(int **array)
{
	int	k;

	k = 0;
	while (array && array[k])
	{
		free(array[k]);
		k++;
	}
	if (array)
		free(array);
}
