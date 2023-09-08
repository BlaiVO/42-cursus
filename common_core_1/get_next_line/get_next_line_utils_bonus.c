/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:08:54 by blvilarn          #+#    #+#             */
/*   Updated: 2023/02/24 19:10:20 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_nl_or_null(char *str, int read_bytes)
{
	int	i;

	i = 0;
	if (read_bytes < BUFFER_SIZE)
		return (1);
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *buffer, char *tmp, int read_bytes)
{
	int		i;
	int		j;
	size_t	size;
	char	*result;

	i = -1;
	j = -1;
	if (read_bytes == 0)
		return (buffer);
	size = ft_strlen(buffer) + ft_strlen(tmp) + 1;
	result = ft_calloc(size, sizeof(char));
	if (!result)
		return (deep_free(&buffer));
	while (buffer[++i] != '\0')
		result[i] = buffer[i];
	while (tmp[++j] != '\0')
		result[i++] = tmp[j];
	deep_free(&buffer);
	return (result);
}

char	*deep_free(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < count * size)
		((char *)mem)[i++] = 0;
	return (mem);
}
