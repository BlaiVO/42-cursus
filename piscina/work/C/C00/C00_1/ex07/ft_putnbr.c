/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:08:04 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/13 12:37:31 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print(char n);
void	ft_putnbr(int nb);
void	recursiva(int nb);

/*
int	main (void)
{
	ft_putnbr(888887);
	print('\n');
	ft_putnbr(-1234537);
	print('\n');
	ft_putnbr(-2147483648);
	return (0);
}
*/

void	print(char n)
{
	write(1, &n, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 10);
	else
	{
		if (nb < 0)
		{
			print('-');
			nb = -nb;
		}
		recursiva(nb);
	}
}

void	recursiva(int nb)
{
	if (nb > 10)
		recursiva(nb / 10);
	print('0' + nb % 10);
}
