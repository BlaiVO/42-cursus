/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:52:55 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/12 14:42:02 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<unistd.h>

/*
void	ft_putchar(char c);

int 	main(void)
{
	ft_putchar('C');
	return (0);
}
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
