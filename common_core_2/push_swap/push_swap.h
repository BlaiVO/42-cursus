/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:20:17 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/13 19:00:35 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct s_num
{
	int	val;
	int	index;
}	t_num;

void	error(char *error);
void	bubble_sort(int *nums, int size);
void	free_the_numbers(int *nums);
int		*get_nums_array(int argc, char **argv);
t_num	*create_stack(int *nums, int len);
int		is_sorted(t_num *stack, int size);
