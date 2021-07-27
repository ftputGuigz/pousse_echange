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

#include <unistd.h>
#include <sys/wait.h>
#include "../libft/libft.h"



t_list	**register_moves_from_stdin(void)
{
	t_list	**solution;
	char	*line;
	int		ret;
	char	*content;
	t_list	*new;

	solution = (t_list **)malloc(sizeof(t_list *));
	if (!solution)
		return (NULL);
	ret = get_next_line(STDIN_FILENO, &line);
	content = ft_strdup(line);
	new = ft_lstnew((void *)content);
	ft_lstadd_back(solution, new);
	while (ret)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		content = ft_strdup(line);
		new = ft_lstnew((void *)content);
		ft_lstadd_back(solution, new);
	}
	return (solution);
}

int	check_pushswap_output(void)
{
	t_list **solution;

	solution = register_moves_from_stdin();
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)ac;
	pid = fork();
	if (pid == 0)
		execve("../push_swap", av + 1, NULL);
	waitpid(pid, 0, 0);
	check_pushswap_output();
	return (0);
}