/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:42 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/19 17:37:40 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		*nums;
	t_stack	stack_a;
	t_stack	stack_b;
	if (argc == 1)
		error("There must be at least 1 argument");
	nums = get_nums_array(argc - 1, &argv[1]);
	stack_a = create_stack(nums, argc - 1);
	stack_b = create_stack(NULL, argc - 1);
	sort_stack(&stack_a, &stack_b);
	return (0);
}
