/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:12:23 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/22 16:46:01 by blvilarn         ###   ########.fr       */
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
		if (s.nums[i].index > max_val)
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
	if (max == a->top + 1)
		rr('a', a);
	if (max == a->top)
		r('a', a);
	if (a->nums[a->top].index > a->nums[a->top + 1].index)
		s('a', a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	while (b->top != b->size - 1)
	{
		if (a->nums[a->top].index == 0)
			p('b', b, a);
		else
			r('a', a);
	}
	sort_three(a);
	p('a', a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (b->top != b->size - 2)
	{
		if (a->nums[a->top].index == 0 || a->nums[a->top].index == 1)
			p('b', b, a);
		else
			r('a', a);
	}
	sort_three(a);
	p('a', a, b);
	p('a', a, b);
	if (a->nums[a->top].index > a->nums[a->top + 1].index)
		s('a', a);
}
