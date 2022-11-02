/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:56:21 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/18 15:02:01 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	auxa;
	int	auxb;

	auxa = *a;
	auxb = *b;
	*a = *a / *b;
	*b = auxa % auxb;
}

/*
int	main(void)
{
	int num1 = 42;
	int	num2 = 10;
	int *a = &num1;
	int *b = &num2;
	
	ft_ultimate_div_mod(a, b);;
	printf("%d", num1);
	printf("%d", num2);
	return (0);
}
*/
