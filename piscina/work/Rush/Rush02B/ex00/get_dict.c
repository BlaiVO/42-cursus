/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:23:27 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/24 19:03:53 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define  ERROR = 1;
#define MALLOC_ERROR = 2;

char	**malloc_char2(int size);
int		*malloc_int(int size);
void	error_log(char *str);

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

int	get_dict(char *dict, char **values, int *keys, int sizes[2])
{
	int		i;
	int		count;

	//keys = malloc_int((sizes[1] + 1) * 4);
	//values = malloc_char2((sizes[1] + 1) * 8);
	keys = malloc((sizes[1] + 1+1) * 4);
	values = malloc((sizes[1] + 1+1) * 8);
	keys[0] = 0;
	values[0] = 0;
	if (values == 0 || keys == 0)
		return (1);
	printf("Keys and values: \n");
	for (int k = 0; k < sizes[1]+1; k++)
	{
		printf("key:%d, val:%p; ", keys[k], values[k]);
	}
	printf("\n");
	i = 0;
	count = 0;
	printf("Sizes: %d %d\n", sizes[0], sizes[1]);
	while (i < sizes[0])
	{
		printf("(fk das shit %d, )", i);
		keys[count] = ft_atoi(&dict[i]);
		printf("k%d ", keys[count]);
		while (!is_char(dict[i]))
			i++;
		values[count] = malloc(end_line(&dict[i] + 1 +2));
		printf("v%s ", values[count]);
		if (!values[count])
			return (2);
		i += copy_str(values[count], &dict[i]) + 1;
		count++;
	}
	return (0);
}
int	main(void)
{
	char	*values[4];
	int		keys[4];
	int		sizes[2] = {21, 3};
	char 	*dict ="1: one\n2: two\n10: ten\n";
	get_dict(dict, values, keys, sizes);
	printf("\n");
	for	(int i = 0; i < 3; i++)
		printf("(main: %s, %d)\n", values[i], keys[i]);
}
