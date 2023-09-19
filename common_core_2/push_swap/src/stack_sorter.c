/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:45:51 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/19 14:15:50 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_stack stack_a, t_stack stack_b)
{
	int	i;

	i = 0;
	while (!is_sorted(stack_a))
	{
		radix(stack_a, stack_b, i);
		i++;
	}
}

void	radix(t_stack stack_a, t_stack stack_b, int bits)
{
	int	i;

	i = 0;
	while (i < stack_a.size)
	{
		if (stack_a.nums[i].index & (1 << bits))
			pb(stack_a, stack_b);
		else
			sa(stack_a, stack_b);
		i++;
	}
}