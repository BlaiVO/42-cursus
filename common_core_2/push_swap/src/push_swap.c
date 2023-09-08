/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:42 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/08 13:53:24 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	*nums;

	i = 0;
	nums = malloc((argc - 1) * sizeof(int));
	while (i < argc)
	{
		nums[i] = ft_atoi(argv[i + 1]);
	}
}
