/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:27:06 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/24 19:03:58 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libc.h>
int	get_dict(char *dict, char **values, int *keys, int sizes[2]);
void	error_log(char *str);
// result[0] = Total_size, result[1] = Total_lines

void	count_size(int f, int result[2])
{
	char	c[1];
	int		ok;
	int		red;

	result[0] = 0;
	result[1] = 0;
	ok = 0;
	red = read(f, c, 1);
	while (red && c[0] != '\0')
	{
		if (ok && c[0] == '\n')
		{
			result[1]++;
			ok = 0;
		}
		else if (c[0] != ' ')
			ok = 1;
		red = read(f, c, 1);
		result[0]++;
	}
}

char	**malloc_char2(int size)
{
	char	**cp;
	int	i;	

	cp = malloc(size);
	if (!cp)
	{
		error_log("Could not reserve memory");
		return cp;
	}
	i = 0;
	while (i < size)
	{
		cp[i] = 0;
		i++;
	}
	return (cp);
}

int	*malloc_int(int size)
{
	int	*ip;
	int	i;	

	ip = malloc(size * 4);
	
	if (!ip)
	{
		error_log("Could not reserve memory");
		return 0;
	}
	i = 0;
	while (i < size)
	{
		ip[i] = 0;
		i++;
	}
	return (ip);
}

void print_dict(int *keys, char **values)
{
	//int i;
	
	(void) values;
	
	printf("%p\n", keys);
	printf("%p\n", values);
	/*
	while(i < 10)
	{
		printf("%d: %s \n", keys[i], values[i]);
		i++;
	}
	*/
}

void	error_log(char *str)
{
	int	len;

	len = 0;
	while(str[len])
		len++;
	write(2, str, len);
	write(2, "\n", 1);
}

int	read_dict(char **values, int *keys, char *dict_name)
{
	int sizes[2];
	int	red;
	int				f;
	char			*raw_dict;

	f = open(dict_name, O_RDONLY);
	count_size(f, sizes);
	close(f);
	f = open(dict_name, O_RDONLY);
	raw_dict = malloc(sizes[0]);
	if (!raw_dict)
	{
		error_log("Could not reserve raw dict memory (read_dict.c/read_dict)");
		return (1);
	}
	red = read(f, raw_dict, sizes[0]);
	close(f);
	if (red != sizes[0])
	{
		error_log("Could not read the dicte");
		return (1);
	}
	if (get_dict(raw_dict, values, keys, sizes))
		return (1);
	return (0);
}

/*
int	main(void)
{
	char	**values;
	int		*keys;	

	values = 0;
	keys = 0;
	if (read_dict(values, keys, "numbers.dict"))
		return (1);
 	print_dict(keys, values);
	return (0);
}
*/
