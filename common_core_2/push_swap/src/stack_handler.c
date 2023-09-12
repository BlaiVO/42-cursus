/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:25:38 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/12 20:17:43 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_num	init_num(int n);
static void		indexate_stack(int *nums, t_num *stack, int size);

t_num	*create_stack(int *nums, int size)
{
	int		i;
	t_num	*stack;

	i = 0;
	stack = malloc(size * sizeof(t_num));
	if (!stack)
	{
		free_the_numbers(nums);
		error("Malloc error");
	}
	while (i < size)
	{
		stack[i] = init_num(nums[i]);
		i++;
	}
	indexate_stack(nums, stack, size);
	return (stack);
}

static t_num	init_num(int n)
{
	t_num	num;

	num.val = n;
	num.index = -1;
	return (num);
}

static void	indexate_stack(int *nums, t_num *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	bubble_sort(nums, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (nums[j] == stack[i].val)
				stack[i].index = j;
			j++;
		}
		i++;
	}
}
