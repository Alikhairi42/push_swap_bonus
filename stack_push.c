/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:31:40 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/06 15:51:40 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->stack_b)
		return ;
	if (list->size_b >= 1)
	{
		tmp = list->stack_b;
		list->stack_b = list->stack_b->next;
		if (list->stack_b)
			list->stack_b->prev = NULL;
		tmp->next = list->stack_a;
		if (list->stack_a)
			list->stack_a->prev = tmp;
		list->stack_a = tmp;
		list->size_a++;
		list->size_b--;
		list->last_a = ft_lstlast(list->stack_a);
		list->last_b = ft_lstlast(list->stack_b);
		if (print)
			write(1, "pa\n", 3);
	}
}

void	pb(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->stack_a)
		return ;
	if (list->size_a >= 1)
	{
		tmp = list->stack_a;
		list->stack_a = list->stack_a->next;
		if (list->stack_a)
			list->stack_a->prev = NULL;
		tmp->next = list->stack_b;
		if (list->stack_b)
			list->stack_b->prev = tmp;
		list->stack_b = tmp;
		list->size_b++;
		list->size_a--;
		list->last_b = ft_lstlast(list->stack_b);
		list->last_a = ft_lstlast(list->stack_a);
		if (print)
			write(1, "pb\n", 3);
	}
}
