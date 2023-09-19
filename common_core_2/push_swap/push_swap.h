/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:20:17 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/19 17:03:28 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct s_num
{
	int	val;
	int	index;
}	t_num;

typedef struct s_stack
{
	int		size;
	int		top;
	t_num	*nums;
}	t_stack;

void	error(char *error);
void	bubble_sort(int *nums, int size);
void	free_the_numbers(int *nums);
int		*get_nums_array(int argc, char **argv);
t_stack	create_stack(int *nums, int size);
int		is_sorted(t_stack stack);
t_num	init_num(int n);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

//Sorting functions
void	p(char letter, t_stack *a, t_stack *b);
void	r(char letter, t_stack *s);
