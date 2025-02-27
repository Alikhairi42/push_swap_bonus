/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bucket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:40 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/25 13:17:08 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int		max;

	if (!stack)
		return (-1);
	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	push_and_sorted(t_list *list)
{
	int	mid;
	int	pos;
	int	max;

	while (list->stack_b)
	{
		mid = list->size_b / 2;
		max = find_max(list->stack_b);
		pos = get_position(list->stack_b, max);
		if (pos <= mid)
		{
			while (list->stack_b && list->stack_b->value != max)
				rb(list, 1);
		}
		else
		{
			while (list->stack_b && list->stack_b->value != max)
				rrb(list, 1);
		}
		pa(list, 1);
	}
}

void	sort_by_packet(t_list *list, int low_range, int high_range)
{
	t_stack	*next;

	while (list->stack_a)
	{
		next = list->stack_a->next;
		if (list->stack_a->index >= low_range
			&& list->stack_a->index <= high_range)
		{
			pb(list, 1);
			low_range++;
			high_range++;
		}
		else if (list->stack_a->index > high_range)
			ra(list, 1);
		else if (list->stack_a->index < low_range)
		{
			pb(list, 1);
			rb(list, 1);
			low_range++;
			high_range++;
		}
		list->stack_a = next;
	}
	push_and_sorted(list);
}
