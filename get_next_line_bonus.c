/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:14:16 by a-khairi          #+#    #+#             */
/*   Updated: 2025/02/26 20:21:06 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*update_static(char *st_buffer)
{
	size_t	i;
	char	*new;

	i = 0;
	while (st_buffer[i] != '\0' && st_buffer[i] != '\n')
		i++;
	if (st_buffer[i] == '\n')
		i++;
	if (st_buffer[i] == 0)
	{
		free(st_buffer);
		return (NULL);
	}
	new = ft_strdup(st_buffer + i);
	if (!new)
		return (NULL);
	free(st_buffer);
	return (new);
}

char	*extract_line(char *st_buffer)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!st_buffer || st_buffer[0] == '\0')
		return (NULL);
	while (st_buffer[i] != '\0' && st_buffer[i] != '\n')
		i++;
	if (st_buffer[i] == '\n')
		i++;
	tmp = ft_substr(st_buffer, 0, i);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*read_and_store(int fd, char *st_buffer)
{
	ssize_t	n_read;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(buffer);
			free(st_buffer);
			return (NULL);
		}
		buffer[n_read] = '\0';
		st_buffer = ft_strjoin(st_buffer, buffer);
		if (ft_strchr(st_buffer, '\n') != NULL || n_read == 0)
			break ;
	}
	free(buffer);
	return (st_buffer);
}

char	*get_next_line(int fd)
{
	static char	*st_buffer[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	st_buffer[fd] = read_and_store(fd, st_buffer[fd]);
	if (!st_buffer[fd])
		return (NULL);
	line = extract_line(st_buffer[fd]);
	st_buffer[fd] = update_static(st_buffer[fd]);
	return (line);
}
