/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utlise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:55 by a-khairi          #+#    #+#             */
/*   Updated: 2025/01/29 18:10:09 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->value = data;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_listadd_back(t_list *list, t_stack *new)
{
	t_stack	*current;

	if (!list || !new)
		return ;
	if (!list->stack_a)
		list->stack_a = new;
	else
	{
		current = list->stack_a;
		while (current)
		{
			if (current->value > new->value)
				current->index++;
			else
				new->index++;
			if (!current->next)
				break ;
			current = current->next;
		}
		current->next = new;
		new->prev = current;
	}
	list->last_a = new;
	list->size_a++;
}

void	free_list(t_list *list)
{
	t_stack	*tmp;

	if (list->stack_a)
	{
		while (list->stack_a)
		{
			tmp = list->stack_a;
			list->stack_a = list->stack_a->next;
			free(tmp);
		}
	}
}

void	setup_stack(t_list	*list, char **av)
{
	int		i;
	long	check;

	list->stack_a = NULL;
	list->stack_b = NULL;
	list->size_a = 0;
	list->size_b = 0;
	i = 0;
	while (i < ft_size_av(av))
	{
		check = ft_atoi(av[i]);
		if (check == LONG_MAX)
		{
			free_av(av);
			free_list(list);
			p_error();
		}
		ft_listadd_back(list, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}
