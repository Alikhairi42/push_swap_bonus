/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utilise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:27:57 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/26 21:34:37 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_move(t_list *list, char *move)
{
	if (!(ft_strcmp(move, "sa\n")))
		sa(list, 0);
	else if (!(ft_strcmp(move, "sb\n")))
		sb(list, 0);
	else if (!(ft_strcmp(move, "ss\n")))
		ss(list, 0);
	else if (!(ft_strcmp(move, "ra\n")))
		ra(list, 0);
	else if (!(ft_strcmp(move, "rb\n")))
		rb(list, 0);
	else if (!(ft_strcmp(move, "rr\n")))
		rr(list, 0);
	else if (!(ft_strcmp(move, "rra\n")))
		rra(list, 0);
	else if (!(ft_strcmp(move, "rrb\n")))
		rrb(list, 0);
	else if (!(ft_strcmp(move, "rrr\n")))
		rrr(list, 0);
	else if (!(ft_strcmp(move, "pa\n")))
		pa(list, 0);
	else if (!(ft_strcmp(move, "pb\n")))
		pb(list, 0);
	else
		p_error();
}
