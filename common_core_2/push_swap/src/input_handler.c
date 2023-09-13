/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:25:17 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/13 18:51:20 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*get_nums_array(int size, char **input)
{
	int	i;
	int	*nums;

	i = 0;
	nums = malloc((size) * sizeof(int));
	if (!nums)
		error("Malloc error");
	while (i < size)
	{
		if (ft_isnum(input[i]) && !ft_memcontains(nums, ft_atoi(input[i]), i))
			nums[i] = ft_atoi(input[i]);
		else
		{
			free_the_numbers(nums);
			error("Invalid input, expected list of unique ints");
		}
		i++;
	}
	return (nums);
}
