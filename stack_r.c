/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:57:47 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/06 15:50:23 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->stack_a)
		return ;
	if (list->stack_a && list->stack_a->next && list->last_a)
	{
		tmp = list->stack_a;
		list->stack_a = list->stack_a->next;
		list->stack_a->prev = NULL;
		list->last_a->next = tmp;
		tmp->prev = list->last_a;
		tmp->next = NULL;
		list->last_a = tmp;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->stack_b)
		return ;
	if (list->stack_b && list->stack_b->next && list->last_b)
	{
		tmp = list->stack_b;
		list->stack_b = list->stack_b->next;
		list->stack_b->prev = NULL;
		list->last_b->next = tmp;
		tmp->prev = list->last_b;
		tmp->next = NULL;
		list->last_b = tmp;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rr(t_list *list, int print)
{
	ra(list, 0);
	rb(list, 0);
	if (print)
		write(1, "rr\n", 3);
}
