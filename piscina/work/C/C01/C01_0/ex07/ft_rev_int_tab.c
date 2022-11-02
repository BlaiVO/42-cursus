/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:12:51 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/15 12:41:11 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	aux;

	i = size - 1;
	j = 0;
	while (i >= size / 2)
	{
		aux = tab[i];
		tab[i] = tab[j];
		tab[j] = aux;
		i--;
		j++;
	}
}

/*
int main(void)
{
	int nums[5] = {1, 2, 3, 4, 5};
	int size;
	int *tab = &nums[0];

	size = 5;

	ft_rev_int_tab(tab, size);
	
	for (int i = 0; i < size; i++)
		printf("%d", nums[i]);
	return (0);
}
*/
