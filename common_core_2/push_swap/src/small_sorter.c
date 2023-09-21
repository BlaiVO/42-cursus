/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:12:23 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/21 20:10:38 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack s)
{
	int	i;
	int	min;
	int	min_val;

	i = s.top;
	min = -1;
	min_val = -1;
	while (i < s.size)
	{
		if (s.nums[i].index < min_val || min_val == -1)
		{
			min = i;
			min_val = s.nums[i].index;
		}
		i++;
	}
	return (min);
}

int	find_max(t_stack s)
{
	int	i;
	int	max;
	int	max_val;

	i = s.top;
	max = -1;
	max_val = -1;
	while (i < s.size)
	{
		if (s.nums[i].index > max_val || max_val == -1)
		{
			max = i;
			max_val = s.nums[i].index;
		}
		i++;
	}
	return (max);
}

void	sort_three(t_stack *a)
{
	int	max;

	max = find_max(*a);
	if (max == 1)
		rr('a', a);
	if (max == 0)
		r('a', a);
	if (!is_sorted(*a))
		s('a', a);
}
