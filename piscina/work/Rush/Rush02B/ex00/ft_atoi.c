/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:56:46 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/24 20:16:13 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define  ERROR = 1;
#define MALLOC_ERROR = 2;

int	ft_atoi(const char *str)
{
	int	size;
	int	num;
	int	zeros;

	size = 0;
	num = 0;
	while (str[size] != ':')
		size++;
	zeros = 1;
	while (size > 0)
	{
		num += (str[size - 1] - '0') * zeros;
		size--;
		zeros *= 10;
	}
	return (num);
}

int	is_char(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	end_line(char *word)
{
	int	i;

	i = 0;
	while (word[i] != '\n')
		i++;
	i++;
	return (i);
}

int	copy_str(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	get_dict(char *dict, char **values, int *keys, int size)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		keys[count] = ft_atoi(&dict[i]);
		while (!is_char(dict[i]))
			i++;
		values[count] = malloc(end_line(&dict[i] + 1));
		if (!values[count])
			return (1);
		i += copy_str(values[count], &dict[i]) + 1;
		count++;
	}
	return (count);
}
