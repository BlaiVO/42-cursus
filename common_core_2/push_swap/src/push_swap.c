/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:42 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/21 20:10:13 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		*nums;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		error();
	nums = get_nums_array(argc - 1, &argv[1]);
	a = create_stack(nums, argc - 1);
	b = create_stack(NULL, argc - 1);
	if (argc <= 6)
		sort_small_stack(&a, &b);
	else
		sort_big_stack(&a, &b);
	return (0);
}
