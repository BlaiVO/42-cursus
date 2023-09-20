/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:45:51 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/20 17:28:15 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	radix(t_stack *a, t_stack *b, int bits);

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (!is_sorted(*stack_a) && i < 10)
	{
		radix(stack_a, stack_b, i);
		i++;
	}
}

static void	radix(t_stack *a, t_stack *b, int bits)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->nums[i].index & (1 << bits))
			p('b', b, a);
		else
			r('a', a);
		i++;
	}
	i = b->top;
	while (i < b->size)
	{
		p('a', a, b);
		i++;
	}
}
