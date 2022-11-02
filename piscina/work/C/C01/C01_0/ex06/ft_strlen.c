/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:49:37 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/13 20:59:23 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		cnt++;
		str++;
	}
	return (cnt);
}

/*
int main(void)
{
	char num;

	num = '0' + ft_strlen("Hola");
	write(1, &num, 1);
	return (0);
}
*/
