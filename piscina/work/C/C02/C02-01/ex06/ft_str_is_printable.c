/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:20:58 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/21 15:58:07 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32)
			return (0);
		str++;
	}
	return (1);
}

/*
int main(void)
{
	char str[3] = ":D ";
	str[2] = 8;
	printf("%d, %d",ft_str_is_printable(str), ft_str_is_printable(">:D"));
	return (0);
}
*/
