/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:10:30 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/14 15:06:49 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int main(void)
{
	int a = 42;
	int	b = 10;
	int c = 0;
	int d = 0;
	int *div = &c;
	int *mod = &d;

	ft_div_mod(a, b, div, mod);
	printf("%d", *div);
	printf("%d", *mod);
}
*/
