/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:39:06 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/12 15:36:09 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

/*
void	print_int(char num);
void	ft_print_comb2(void);

int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/

void	print_int(char num)
{
	write (1, &num, 1);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			print_int(num1 / 10 + '0');
			print_int(num1 % 10 + '0');
			write(1, " ", 1);
			print_int(num2 / 10 + '0');
			print_int(num2 % 10 + '0');
			if (!(num1 == 98 && num2 == 99))
				write(1, ", ", 2);
			num2++;
		}
		num1++;
	}
}
