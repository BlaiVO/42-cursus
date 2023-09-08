/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:21:04 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/04 17:23:08 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	sum_complex(t_complex x, t_complex y)
{
	t_complex	result;

	result.a = x.a + y.a;
	result.b = x.b + y.b;
	return (result);
}

t_complex	mult_complex(t_complex x, t_complex y)
{
	t_complex	result;

	result.a = x.a * y.a - x.b * y.b;
	result.b = x.a * y.b + x.b * y.a;
	return (result);
}
