/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:32:09 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/05 12:29:30 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define I 34
# define J 38
# define K 40
# define L 37
# define Q 12
# define O 31
# define P 35

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}		t_img;

typedef struct s_complex
{
	double	a;
	double	b;
}	t_complex;

typedef struct s_handler
{
	t_win		win;
	t_img		img;
	char		fract;
	t_complex	param_julia;
}	t_handler;

//mlx
t_win			new_program(int w, int h, char *str);
t_img			new_img(int w, int h, t_win window);
void			put_pixel_img(t_img img, int x, int y, int color);
void			init_handler(t_handler *handler, char fractal, t_complex c);

//math
t_complex		sum_complex(t_complex x, t_complex y);
t_complex		mult_complex(t_complex x, t_complex y);

//fractals
void			mandelbrot(t_handler hand);
void			julia(t_handler hand, t_complex c);
void			print_fractal(t_handler handler);

//hooks
int				exit_window(t_handler *handler);
int				key_press(int key, t_handler *handler);
int				scroll(int key, int x, int y, t_handler *handler);

//colors
unsigned int	get_color(int n);

#endif