/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:43:46 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/18 15:21:32 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)

{
	int	i;
	int	y;
	int	aux;

	i = 0;
	while (i < size)
	{
		y = 0;
		while (y < size)
		{
			if (y != i)
			{
				if (tab[i] < tab[y])
				{
					aux = tab[i];
					tab[i] = tab [y];
					tab[y] = aux;
				}
			}
			y++;
		}
		i++;
	}
}

/*
int main(void)
{
	int size = 10;
	int nums[10] = {8, 4, 5, 6, 2, 1, 9, 7, 3, 0};
	
	ft_sort_int_tab(nums, size);

	for (int i = 0; i < size; i++)
		printf("%d", nums[i]);
}
*/
