/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utilise.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:56:52 by a-khairi          #+#    #+#             */
/*   Updated: 2025/01/29 17:42:37 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		i;
	int		sn;
	long	rest;

	sn = 1;
	rest = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sn = -1;
		i++;
	}
	if (!ft_str_digit(str + i))
		return (LONG_MAX);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		rest = rest * 10 + (str[i] - '0');
		i++;
		if (rest * sn > INT_MAX || rest * sn < INT_MIN)
			return (LONG_MAX);
	}
	return (rest * sn);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isallspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
			return (1);
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_digit(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_dup(char **avgs)
{
	int	i;
	int	j;

	i = 0;
	while (avgs[i])
	{
		j = i + 1;
		while (avgs[j])
		{
			if (ft_atoi(avgs[i]) == ft_atoi(avgs[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
