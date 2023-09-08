/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:09:32 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/05 15:33:40 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	get_iterations(t_complex z, t_complex c);

void	julia(t_handler hand, t_complex c)
{
	int			x;
	int			y;
	t_complex	z;
	int			iterations;

	x = -1;
	while (++x < hand.win.width)
	{
		y = -1;
		while (++y < hand.win.height)
		{
			z.a = hand.img.x_min + x * (hand.img.x_max - hand.img.x_min)
				/ hand.img.w;
			z.b = (-1 * hand.img.y_max) + y * (hand.img.y_max - hand.img.y_min)
				/ hand.img.h;
			iterations = get_iterations(z, c);
			if (iterations >= 100)
				put_pixel_img(hand.img, x, y, 0x000000);
			else
				put_pixel_img(hand.img, x, y, get_color(iterations % 10));
		}
	}
	mlx_put_image_to_window(hand.win.mlx_ptr, \
		hand.win.win_ptr, hand.img.img_ptr, 0, 0);
}

static int	get_iterations(t_complex z, t_complex c)
{
	int			iterations;
	double		abs;

	iterations = 0;
	while (iterations < 100)
	{
		z = sum_complex(mult_complex(z, z), c);
		abs = z.a * z.a + z.b * z.b;
		if (abs > 4)
			return (iterations);
		iterations++;
	}
	return (iterations);
}
