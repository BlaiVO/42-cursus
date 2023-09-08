/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:24:48 by blvilarn          #+#    #+#             */
/*   Updated: 2023/01/27 15:32:24 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, char *buffer)
{
	char	*tmp;
	int		read_bytes;
	int		nl;

	read_bytes = 1;
	nl = 0;
	while (!nl && read_bytes > 0)
	{
		tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!tmp)
			return (deep_free(&buffer));
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
			return (deep_free(&tmp), deep_free(&buffer));
		if (is_nl_or_null(tmp, read_bytes))
			nl = 1;
		buffer = ft_strjoin(buffer, tmp, read_bytes);
		if (!buffer)
			return (deep_free(&tmp));
		deep_free(&tmp);
	}
	return (buffer);
}

static char	*clean_line(char *buffer)
{
	int		size;
	int		i;
	char	*line;

	size = 0;
	i = 0;
	while (buffer[size] != '\0' && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	if (size == 0)
		return (NULL);
	line = ft_calloc((size + 1), sizeof(char));
	if (!line)
		return (NULL);
	while (i < size && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

static char	*clean_buffer(char *buffer)
{
	int		size;
	int		i;
	char	*new_buffer;

	size = 0;
	i = 0;
	while (buffer[size] != '\0' && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	if (buffer[size] == '\0')
		return (deep_free(&buffer));
	while (buffer[size + i] != '\0')
		i++;
	new_buffer = ft_calloc((i + 1), sizeof(char));
	if (!new_buffer)
		return (deep_free(&buffer));
	i = -1;
	while (buffer[++size - 1] != '\0')
		new_buffer[++i] = buffer [size - 1];
	deep_free(&buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	buffer = get_line(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = clean_line(buffer);
	if (!next_line)
		return (deep_free(&buffer));
	buffer = clean_buffer(buffer);
	return (next_line);
}
