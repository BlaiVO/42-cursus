/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:10:54 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/22 18:00:40 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	s(char letter, t_stack *s)
{
	t_num	aux;

	aux = s->nums[s->top];
	s->nums[s->top] = s->nums[s->top + 1];
	s->nums[s->top + 1] = aux;
	if (letter == 'a' || letter == 'b')
		ft_printf("s%c\n", letter);
}

void	ss(t_stack *a, t_stack *b)
{
	s('s', a);
	s('s', b);
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
	s->nums[i - 1] = aux;
	ft_printf("r%c\n", letter);
}

void	rr(char letter, t_stack *s)
{
	int		i;
	t_num	aux;

	i = s->size;
	aux = s->nums[s->size - 1];
	while (i > s->top)
	{
		s->nums[i] = s->nums[i - 1];
		i--;
	}
	s->nums[s->top] = aux;
	ft_printf("rr%c\n", letter);
}
