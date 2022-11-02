/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:56:49 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/12 15:21:52 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
void	ft_print_comb(void);

int	main(void)
{
	ft_print_comb();
	return (0);
}
*/

void	ft_print_comb(void)
{
	char	x;
	char	y;
	char	z;

	x = '0';
	while (x <= '7')
	{
		y = x + 1;
		while (y <= '8')
		{
			z = y + 1;
			while (z <= '9')
			{
				write (1, &x, 1);
				write (1, &y, 1);
				write (1, &z, 1);
				if (!(x == '7' && y == '8' && z == '9'))
					write (1, ", ", 2);
				z++;
			}
			y++;
		}
		x++;
	}
}
