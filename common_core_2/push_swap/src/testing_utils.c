/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:14:17 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/21 20:04:16 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack s, char letter)
{
	int	i;

	i = 0;
	while (i < s.size)
	{
		if (i == s.top)
			ft_printf("T ");
		ft_printf("%i %i\n", s.nums[i].val, s.nums[i].index);
		i++;
	}
	ft_printf("-----\n");
	ft_printf("  %c\n", letter);
}

void	print_stacks(t_stack a, t_stack b)
{
	int	i;

	i = 0;
	while (i < a.size)
	{
		ft_printf("%i    %i\n", a.nums[i].index, b.nums[i].index);
		i++;
	}
	ft_printf("---  ---\n");
	ft_printf(" a    b\n");
}
