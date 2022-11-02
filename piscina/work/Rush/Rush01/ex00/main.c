/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:19:59 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/17 18:15:18 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//No hemos podido hacer la logica. Hemos imprimido la matriz en vez de eso.

void	compute(char *limits);

int	main(int argc, char *args[])
{
	char	limits[16];
	char	*numeros_ptr;
	int		i;

	numeros_ptr = args[1];
	i = -1;
	while (++i < 16)
	{
		limits[i] = (*numeros_ptr);
		numeros_ptr += 2;
	}
	compute(limits);
	return (0);
}

void	compute(char *limits)
{
	int	c;
	int	l;

	c = 0;
	l = 0;
	while (l < 4)
	{
		while (c < 4)
		{
			write(1, &limits[l * 4 + c], 1);
			c++;
			if (c != 4)
				write(1, " ", 1);
		}
		c = 0;
		write(1, "\n", 1);
		l++;
	}
}
