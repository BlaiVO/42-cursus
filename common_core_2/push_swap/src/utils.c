/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:32:12 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/12 19:58:48 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(char *error)
{
	ft_printf("ERROR: %s\n", error);
	exit(1);
}

void	bubble_sort(int *nums, int size)
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
				if (nums[i] < nums[y])
				{
					aux = nums[i];
					nums[i] = nums [y];
					nums[y] = aux;
				}
			}
			y++;
		}
		i++;
	}
}

void	free_the_numbers(int *nums)
{
	if (nums)
		free(nums);
}
