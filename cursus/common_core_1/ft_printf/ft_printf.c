/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:33:29 by blvilarn          #+#    #+#             */
/*   Updated: 2023/01/09 19:33:46 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_content(const char *str, va_list ptr, int *i, int *len)
{
	if (str[*i] == 'c')
		return (ft_putchar(va_arg(ptr, int), i, len));
	if (str[*i] == 's')
		return (ft_putstr(va_arg(ptr, char *), i, len));
	if (str[*i] == 'p')
		return (-1);
	if (str[*i] == 'd' || str[*i] == 'i')
		return (-1);
	if (str[*i] == 'u')
		return (-1);
	if (str[*i] == 'x')
		return (-1);
	if (str[*i] == 'X')
		return (-1);
	if (str[*i] == '%')
		return (ft_putchar('%', i, len));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	va_start(ptr, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			len++;
			i++;
		}
		else
		{
			i++;
			if (print_content(str, ptr, &i, &len) == -1)
				return (-1);
		}
	}
	return (len);
}
