/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:13 by a-khairi          #+#    #+#             */
/*   Updated: 2025/01/29 17:03:25 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_len(int ac, char **av)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		j = 0;
		if (ft_isallspace(av[i]) || av[i][0] == '\0')
			p_error();
		while (av[i][j])
		{
			len++;
			j++;
		}
		if (i < ac - 1)
			len++;
		i++;
	}
	return (len);
}

void	free_av(char **avgs)
{
	char	**current;

	if (!avgs)
		return ;
	current = avgs;
	while (*current)
	{
		free(*current);
		current++;
	}
	free(avgs);
}

int	ft_size_av(char **avgs)
{
	int	len;

	len = 0;
	while (*avgs != NULL)
	{
		len++;
		avgs++;
	}
	return (len);
}

char	*cat_input(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	*cat;

	i = 1;
	j = 0;
	k = 0;
	cat = malloc(check_len(ac, av) + 1);
	if (!cat)
		p_error();
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			cat[k++] = av[i][j++];
		if (i < ac - 1)
			cat[k++] = ' ';
		i++;
	}
	cat[k] = '\0';
	return (cat);
}

void	p_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
