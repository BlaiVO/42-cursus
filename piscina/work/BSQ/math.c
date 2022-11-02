/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:06:29 by alrodri2          #+#    #+#             */
/*   Updated: 2022/07/26 12:16:24 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_recursive_power(int nb, int power);

int ft_atoi(char *str)
{
	int i;
	int pot;
	int num;
	int j;

	//write(1, "S", 1);
	i = 0;
	//write(1, &str[i], 1);
	if ((str[i] < 48 || str[i] > 57))
		return (-1);
//	write(1, "X", 1);
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	pot = ft_recursive_power(10, (i - 1));
	j = 0;
	num = 0;
	while (pot > 1 && j <= i)
	{
		num += ((str[j] % 48) * pot);
		j++;
		pot = pot / 10;
	}
	return (num);
}

int ft_recursive_power(int nb, int power)
{
	if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	if (power < 0)
		return (0);
	return (1);
}
/**
char *ft_afatoi(char *str)
{
	int i;
	char characters[3]
int main()
{
	printf("%d", ft_atoi("10.ox"));
}**/
