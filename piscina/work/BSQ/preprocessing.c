/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 06:40:05 by alrodri2          #+#    #+#             */
/*   Updated: 2022/07/26 12:16:21 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int ft_atoi(char *str);

char *ft_afatoi(char *line)
{
	int i;
	int j;
	char characters[3];

	while (line[i] >= 48 && line[i] <= 57)
		i++;
	j = 0;
	while (line[i] != '\0')
	{
		characters[j] = line[i];
		if (j + 1 > 2)
			return (0);
		j++;
		i++;
	}
	return (characters);
}

char	*first_line(char *map)
{
	//1 - Check if map follows all the rules
	/** Definition of a valid map **
	 * All lines have the same length
	 * There is at least one line of at least one box
	 * At each end of line, there is a linebreak
	 * The characters on the map can only be those introduced in the first line
	 **/
	//2 - Return 0 if it does not follow the rules and 1 if it does
	int fd;
	char arr [1];
	int bytes_read = 1;
	int total = 0;
	char *str;

	fd = open(map, O_RDONLY);
	while (bytes_read > 0 && arr[0] != '\n')
	{
		bytes_read = read(fd, arr, 1);
		total += bytes_read;
	}
	close(fd);
	str = (char *)malloc(sizeof(char) * (total));
	fd = open(map, O_RDONLY);
	read(fd, str, total);
	return (str);	
}

int	map_validity(char *map, int num_lines, char *legend)
{
	return 0;
}

char 	**save_map_outline(char *map)
{
	//1 - Save the map in a n*n array
	//2 - Return the array (it will be a malloc so we have to free it
	/** Input map structure **
	 * First line contains information on how to read the map
	 * 1 - number of lines on the map
	 * 2 - empty character
	 * 3 - obstacle character
	 * 4 - full character
	 * The initial map only contains empty and obstacle characters
	 **/

	/**Saved map structure**
	 *[[X00 X01 X02 ... X0n]
	 * [X10 X11 X12 ... X1n]
	 * [:	:	Xij	... :  ]
	 * [Xn0 Xn1 Xn2 ... Xnn]]
	 **/
	int fd;
	char arr[1];
	int bytes_read;
	char **string;
	int i;

	fd = open(map, O_RDONLY);
	i = 0;
//	write(1, "S", 1);
	while (bytes_read > 0 && (arr[0] != '\n' || i == 0))
	{
		if (arr[0] == '\n')
			i = 1;
		if (i == 0)
			bytes_read = read(fd, arr, 1);
		else
		{
			bytes_read = read(fd, arr, 1);
			i += bytes_read;
		}

	}
//	write(1, &arr, 1);
//	write(1, "D", 1);
	close(fd);
	string = (char **)malloc(sizeof(char *) * 9);//ft_atoi(first_line(map)));
	i = 0;
	while (i <= ft_atoi(first_line(map)))
	{
		string[i] = (char *)malloc(sizeof(char) * 100);
		i++;
	}
//	write(1, "k", 1);
	//write(1, &string[0][0], 1);
//	write(1, "F", 1);	
	return (string);

}

char **write_map(char *map, char **outline)
{
	int fd;
	char arr[1];
	int bytes_read;
	int i;
	int j;

	fd = open(map, O_RDONLY);
	i = -1;
	bytes_read = read(fd, arr, 1);
	while (bytes_read > 0)
	{
		if (i != -1)
		{	
			j = 0;
			while (arr[0] != '\n')
			{
				outline[i][j] = arr[0];
				j++;
				bytes_read = read(fd, arr, 1);
			}
			i++;
		}
		else
		{
			write(1, "s", 1);
			if (arr[0] != '\n')
				bytes_read = read(fd, arr, 1);
			else
				i++;
		}
	}
	return (outline);
}

			

/**
char	**preprocessing(char *map)
{
	if (check_validity_outline(map) == 1)
		return (save_map(map));
	write(1, "Map Error", 9);
	return (0);
}**/
	
int main()
{
//	printf("%d", ft_atoi("10.ox"));
	printf("%c", write_map("example", save_map_outline("example"))[0][0]);
}

