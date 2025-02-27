/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:58:15 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/06 15:50:18 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->stack_a)
		return ;
	if (list->stack_a && list->last_a && list->stack_a != list->last_a)
	{
		tmp = list->last_a;
		list->last_a = list->last_a->prev;
		list->last_a->next = NULL;
		tmp->prev = NULL;
		tmp->next = list->stack_a;
		list->stack_a->prev = tmp;
		list->stack_a = tmp;
		if (print)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->stack_b)
		return ;
	if (list->stack_b && list->last_b && list->stack_b != list->last_b)
	{
		tmp = list->last_b;
		list->last_b = list->last_b->prev;
		list->last_b->next = NULL;
		tmp->prev = NULL;
		tmp->next = list->stack_b;
		list->stack_b->prev = tmp;
		list->stack_b = tmp;
		if (print)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list *list, int print)
{
	rra(list, 0);
	rrb(list, 0);
	if (print)
		write(1, "rrr\n", 4);
}
