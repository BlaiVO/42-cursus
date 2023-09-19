/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:25:38 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/19 14:07:03 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static		t_num	init_num(int n);
static void	index_stack(int *nums, t_stack stack);

t_stack	create_stack(int *nums, int size)
{
	int		i;
	t_stack	stack;

	i = 0;
	stack.size = size;
	stack.nums = malloc(size * sizeof(t_num));
	if (!stack.nums)
	{
		free_the_numbers(nums);
		error("Malloc error");
	}
	while (i < size && nums)
	{
		stack.nums[i] = init_num(nums[i]);
		i++;
	}
	if (nums)
		index_stack(nums, stack);
	return (stack);
}

static t_num	init_num(int n)
{
	t_num	num;

	num.val = n;
	num.index = -1;
	return (num);
}

static void	index_stack(int *nums, t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	bubble_sort(nums, stack.size);
	while (i < stack.size)
	{
		j = 0;
		while (j < stack.size)
		{
			if (nums[j] == stack.nums[i].val)
			{
				stack.nums[i].index = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
