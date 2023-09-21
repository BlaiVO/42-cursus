/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:20:17 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/21 20:11:14 by blvilarn         ###   ########.fr       */
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

//utils
void	error(void);
void	bubble_sort(int *nums, int size);
void	free_the_numbers(int *nums);
int		is_sorted(t_stack stack);

//stack_handler
t_num	init_num(int n);
t_stack	create_stack(int *nums, int size);

//input_handler
int		*get_nums_array(int argc, char **argv);

//stack_sorter
void	sort_big_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_small_stack(t_stack *a, t_stack *b);

//small_sorter
int		find_min(t_stack s);
int		find_max(t_stack s);
void	sort_three(t_stack *a);

//simple_operations
void	p(char letter, t_stack *a, t_stack *b);
void	r(char letter, t_stack *s);
void	s(char letter, t_stack *s);
void	rr(char letter, t_stack *s);

//testing_utils
void	print_stack(t_stack s, char letter);
void	print_stacks(t_stack a, t_stack b);
