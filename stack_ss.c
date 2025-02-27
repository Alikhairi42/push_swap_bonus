/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:58:18 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/06 15:50:01 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s1, t_stack *s2)
{
	int	tmp;

	tmp = s1->value;
	s1->value = s2->value;
	s2->value = tmp;
	tmp = s1->index;
	s1->index = s2->index;
	s2->index = tmp;
}

void	sa(t_list *list, int print)
{
	if (!list->stack_a)
		return ;
	if (list->size_a >= 2)
	{
		swap(list->stack_a, list->stack_a->next);
		list->last_a = ft_lstlast(list->stack_a);
		if (print)
			write(1, "sa\n", 3);
	}
}

void	sb(t_list *list, int print)
{
	if (!list->stack_b)
		return ;
	if (list->size_b >= 2)
	{
		swap(list->stack_b, list->stack_b->next);
		list->last_b = ft_lstlast(list->stack_b);
		if (print)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list *list, int print)
{
	sa(list, 0);
	sb(list, 0);
	if (print)
		write(1, "ss\n", 3);
}
