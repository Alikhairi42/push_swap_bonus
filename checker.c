/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:23:45 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/27 15:05:39 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display(t_list *list)
{
	if (list->stack_a && is_sorted(list->stack_a) && list->stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	execute_moves(t_list *list)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		check_move(list, move);
		move = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	list;
	char	*cat;
	char	**avg;

	if (ac == 1)
		return (0);
	cat = cat_input(ac, av);
	avg = ft_split(cat, ' ');
	free(cat);
	if (ft_check_dup(avg))
	{
		free_av(avg);
		p_error();
	}
	setup_stack(&list, avg);
	free_av(avg);
	execute_moves(&list);
	ft_display(&list);
	return (free_list(&list), 0);
}
