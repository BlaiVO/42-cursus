/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:10:54 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/13 19:28:16 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
- sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
- rrr : rra and rrb at the same time.
*/

void	s(t_num *stack, char letter)
{
	t_num	aux;

	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
	if (letter == 'a' || letter == 'b')
		ft_printf("s%c\n", letter);
}

void	ss(t_num *stack_a, t_num *stack_b)
{
	s(stack_a, 's');
	s(stack_b, 's');
	ft_printf("ss\n");
}
