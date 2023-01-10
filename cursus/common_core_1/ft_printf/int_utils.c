/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:29:19 by blvilarn          #+#    #+#             */
/*   Updated: 2023/01/10 19:54:13 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_absval(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int	ft_putnumber(int n, int *i, int *len)
{
	char	abs;

	(*i)++;
	if (n == 0)
	{
		(*len)++;
		if (write(1, "0", 1) != 1)
			return (-1);
	}
	if (n < 0)
	{
		(*len)++;
		if (write(1, "-", 1) != 1)
			return (-1);
	}
	while (n)
	{
		abs = ft_absval(n % 10) + '0';
		(*len)++;
		if (write(1, &abs, 1) != 1)
			return (-1);
		n /= 10;
	}
	return (0);
}
