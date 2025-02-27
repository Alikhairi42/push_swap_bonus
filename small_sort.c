/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:34 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/25 13:17:37 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_elements(t_list *list)
{
	int	fr1;
	int	sc2;
	int	th3;

	fr1 = list->stack_a->index;
	sc2 = list->stack_a->next->index;
	th3 = list->stack_a->next->next->index;
	if (fr1 > sc2 && fr1 > th3 && sc2 > th3)
	{
		sa(list, 1);
		rra(list, 1);
	}
	else if (fr1 > sc2 && fr1 > th3 && sc2 < th3)
		ra(list, 1);
	else if (fr1 < sc2 && fr1 > th3 && sc2 > th3)
		rra(list, 1);
	else if (fr1 > sc2 && fr1 < th3 && sc2 < th3)
		sa(list, 1);
	else if (fr1 < sc2 && fr1 < th3 && sc2 > th3)
	{
		sa(list, 1);
		ra(list, 1);
	}
}

void	push_min_to_b(t_list *list, int pos, int len_stack)
{
	if (pos <= 1)
	{
		if (pos == 1)
			sa(list, 1);
		pb(list, 1);
		return ;
	}
	if (pos <= len_stack / 2)
	{
		while (pos-- > 0)
			ra(list, 1);
	}
	else
	{
		while (pos++ < len_stack)
			rra(list, 1);
	}
	pb(list, 1);
}

void	sort_4_or_5(t_list *list)
{
	t_stack	*current;
	int		pos;
	int		i;

	i = 0;
	while (i <= list->size_a - 3)
	{
		current = list->stack_a;
		pos = 0;
		while (current)
		{
			if (current->index == i)
			{
				push_min_to_b(list, pos, list->size_a);
				break ;
			}
			pos++;
			current = current->next;
		}
		i++;
	}
	sort_3_elements(list);
	pa(list, 1);
	pa(list, 1);
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_stack(t_list *list)
{
	int	low_range;
	int	high_range;

	if (!list)
		return ;
	low_range = 0;
	high_range = list->size_a * 0.048 + 10;
	if (list->size_a == 2)
	{
		if (list->stack_a->index > list->stack_a->next->index)
			sa(list, 1);
	}
	else if (list->size_a == 3)
		sort_3_elements(list);
	else if (list->size_a <= 5)
		sort_4_or_5(list);
	else
		sort_by_packet(list, low_range, high_range);
}
