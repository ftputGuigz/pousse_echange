/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:37:49 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/27 14:28:42 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stdio.h"
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list *start;
	int	i;

	i = 0;
	start = lst;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	lst = start;
	return (i);
}
