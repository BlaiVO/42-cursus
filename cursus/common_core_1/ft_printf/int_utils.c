/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:29:19 by blvilarn          #+#    #+#             */
/*   Updated: 2023/01/12 20:17:05 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recursiva(long long n, int *len)
{
	char	c;

	if (n >= 10)
	{
		if (recursiva(n / 10, len) == -1)
			return (-1);
	}
	c = '0' + n % 10;
	if (write(1, &c, 1) != 1)
		return (-1);
	(*len)++;
	return (0);
}

int	ft_putnumber(long long n, int *i, int *len)
{
	(*i)++;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
			return (-1);
		(*len) += 11;
	}
	else
	{
		if (n < 0)
		{
			if (write(1, "-", 1) != 1)
				return (-1);
			(*len)++;
			n = -n;
		}
		if (recursiva(n, len) == -1)
			return (-1);
	}
	return (0);
}

static int	get_len_base(unsigned long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	pnbr_b(char *base_str, unsigned long n, int *i, int *len)
{
	char	buffer[17];
	int		base;
	int		j;

	base = ft_strlen(base_str);
	j = get_len_base(n, base);
	(*i)++;
	buffer[j] = '\0';
	if (n == 0)
	{
		(*len)++;
		return (write(1, "0", 1));
	}
	while (n)
	{
		buffer[--j] = base_str[n % base];
		n /= base;
	}
	return (ft_putstr(buffer, &j, len));
}
