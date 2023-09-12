/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:42 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/12 20:16:53 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		*nums;
	t_num	*stack;

	if (argc == 1)
		error("There must be at least 1 argument");
	nums = get_nums_array(argc - 1, &argv[1]);
	stack = create_stack(nums, argc - 1);
	int	i = 0;
	while (i < argc -1)
	{
		ft_printf("val: %i, index: %i\n", stack[i].val, stack[i].index);
		i++;
	}
	return (0);
}
