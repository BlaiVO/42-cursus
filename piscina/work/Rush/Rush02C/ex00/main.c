/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:14:26 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/24 21:50:15 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_dict(char *dict, char **values, int *keys, int size);
void	print_int(int num);
void	print_str(char *str);
char	*read_dict(char	*dict_name);

int	main(void)
{
	char	*values[100];
	int		keys[45];
	int		i;
	char 	*dict;

	
	dict = read_dict("numbers.dict");
	write(1, dict, 691);
	write(1,"wololoooo", 7);
	dict = NULL;
	//get_dict("1: one\n2: two\n10: ten\n", values, keys, 21);
	get_dict(dict,  values, keys, 691);
	write(1, "\n", 1);
	i = 0;
	while (i < 3)
	{
		print_int(keys[i]);
		write(1, ": ", 2);
		print_str(values[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

void	print_int(int num)
{
	char	d1;
	char	d2;

	if (num >= 10)
	{
		d1 = num / 10 + '0';
		d2 = num % 10 + '0';
		write(1, &d1, 1);
		write(1, &d2, 1);
	}
	else
	{
		d1 = num + '0';
		write(1, &d1, 1);
	}
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
