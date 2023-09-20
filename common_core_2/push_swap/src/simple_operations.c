/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:10:54 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/20 13:29:37 by blvilarn         ###   ########.fr       */
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

void	s(t_stack *stack, char letter)
{
	t_num	aux;

	aux = stack->nums[stack->top];
	stack->nums[stack->top] = stack->nums[1];
	stack->nums[1] = aux;
	if (letter == 'a' || letter == 'b')
		ft_printf("s%c\n", letter);
}

void	ss(t_stack *a, t_stack *b)
{
	s(a, 's');
	s(b, 's');
	ft_printf("ss\n");
}

void	p(char letter, t_stack *a, t_stack *b)
{
	t_num	aux;

	aux = b->nums[b->top];
	b->nums[b->top] = init_num(-1);
	b->top++;
	a->top--;
	a->nums[a->top] = aux;
	ft_printf("p%c\n", letter);
}

void	r(char letter, t_stack *s)
{
	int		i;
	t_num	aux;

	i = s->top;
	aux = s->nums[s->top];
	while (i < s->size)
	{
		s->nums[i] = s->nums[i + 1];
		i++;
	}
	s->nums[i] = aux;
	ft_printf("r%c\n", letter);
}
