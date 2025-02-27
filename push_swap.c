/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:19 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/26 21:23:58 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!is_sorted(list.stack_a))
		sort_stack(&list);
	free_list(&list);
	return (0);
}
