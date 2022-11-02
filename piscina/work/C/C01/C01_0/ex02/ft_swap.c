/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:22:13 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/14 13:32:57 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

/*
int main(void)
{
	int num1 = 2;
	int num2 = 4;
	int *a = &num1;
	int	*b = &num2;

	ft_swap(a, b);
	printf("%d", num1);
	printf("%d", num2);
}
*/
