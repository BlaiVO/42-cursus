/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:28 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/05 15:45:28 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	exit_window(t_handler *handler)
{
	if (handler)
		mlx_destroy_window(handler->win.mlx_ptr, handler->win.win_ptr);
	exit(EXIT_SUCCESS);
}

static void	arrow_keys(t_handler *hand, int key, double dist_y, double dist_x)
{
	if (key == UP || key == I)
	{
		hand->img.y_min += 0.2 * dist_y;
		hand->img.y_max += 0.2 * dist_y;
		print_fractal(*hand);
	}
	if (key == DOWN || key == K)
	{
		hand->img.y_min -= 0.2 * dist_y;
		hand->img.y_max -= 0.2 * dist_y;
		print_fractal(*hand);
	}
	if (key == LEFT || key == J)
	{
		hand->img.x_min -= 0.2 * dist_x;
		hand->img.x_max -= 0.2 * dist_x;
		print_fractal(*hand);
	}
	if (key == RIGHT || key == L)
	{
		hand->img.x_min += 0.2 * dist_x;
		hand->img.x_max += 0.2 * dist_x;
		print_fractal(*hand);
	}
}

int	key_press(int key, t_handler *handler)
{
	if (key == ESC || key == Q)
		exit_window(handler);
	if (key == O)
		scroll(SCROLL_DOWN, 0, 0, handler);
	if (key == P)
		scroll(SCROLL_UP, 0, 0, handler);
	arrow_keys(
		handler, key, handler->img.y_max - handler->img.y_min,
		handler->img.x_max - handler->img.x_min
		);
	return (0);
}

int	scroll(int key, int x, int y, t_handler *handler)
{
	double	dist_x;
	double	dist_y;

	(void)x, (void)y;
	dist_x = handler->img.x_max - handler->img.x_min;
	dist_y = handler->img.y_max - handler->img.y_min;
	if (key == SCROLL_UP)
	{
		handler->img.x_min += 0.2 * dist_x;
		handler->img.x_max -= 0.2 * dist_x;
		handler->img.y_min += 0.2 * dist_y;
		handler->img.y_max -= 0.2 * dist_y;
		print_fractal(*handler);
	}
	if (key == SCROLL_DOWN)
	{
		handler->img.x_min -= 0.2 * dist_x;
		handler->img.x_max += 0.2 * dist_x;
		handler->img.y_min -= 0.2 * dist_y;
		handler->img.y_max += 0.2 * dist_y;
		print_fractal(*handler);
	}
	return (0);
}
