/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:11:15 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/05 13:51:05 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	image.x_min = -2;
	image.x_max = 2;
	image.y_min = -2;
	image.y_max = 2;
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	init_handler(t_handler *handler, char fractal, t_complex c)
{
	handler->win = new_program(1000, 1000, "fractol blvilarn");
	if (handler->win.win_ptr)
		handler->img = new_img(1000, 1000, handler->win);
	handler->fract = fractal;
	handler->param_julia = c;
}
