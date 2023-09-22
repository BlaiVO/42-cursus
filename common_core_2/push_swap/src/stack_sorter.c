/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:45:51 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/22 16:47:02 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	radix(t_stack *a, t_stack *b, int bits);

void	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (!is_sorted(*stack_a))
	{
		radix(stack_a, stack_b, i);
		i++;
	}
}

void	sort_small_stack(t_stack *a, t_stack *b)
{
	(void)b;
	if (!is_sorted(*a))
	{
		if (a->size == 2)
			r('a', a);
		if (a->size == 3)
			sort_three(a);
		if (a->size == 4)
			sort_four(a, b);
		if (a->size == 5)
			sort_five(a, b);
	}
}

static void	radix(t_stack *a, t_stack *b, int bits)
{
	int	i;

	i = 0;
	while (i < a->size && !is_sorted(*a))
	{
		if (!(a->nums[a->top].index & (1 << bits)))
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
