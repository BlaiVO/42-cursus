/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:07:04 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/05 15:35:31 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	invalid_input(void)
{
	ft_printf("Invalid input. Avilable inputs:\n%% mandelbrot\n%% julia a b\n");
	exit (1);
}

static void	validate_input(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 2 && argc != 4)
		invalid_input();
	if (ft_memcmp("mandelbrot", argv[1], 11) != 0 && \
		ft_memcmp("julia", argv[1], 6) != 0)
		invalid_input();
	if ((argv[1][0] == 'm' && argc == 4) || (argv[1][0] == 'j' && argc == 2))
		invalid_input();
	if (argv[1][0] == 'j')
	{
		while (argv[2][++i])
		{
			if (!ft_isdigit(argv[2][i]) && ft_strchr(".-", argv[2][i]) == NULL)
				invalid_input();
		}
		i = -1;
		while (argv[3][++i])
		{
			if (!ft_isdigit(argv[3][i]) && ft_strchr(".-", argv[3][i]) == NULL)
				invalid_input();
		}
	}
}

void	print_fractal(t_handler handler)
{
	if (handler.fract == 'm')
		mandelbrot(handler);
	if (handler.fract == 'j')
		julia(handler, handler.param_julia);
}

static void	print_controls(char **argv)
{
	if (argv[1][0] == 'm')
		ft_printf("%s", "You are printing: mandelbrot\n");
	else
		ft_printf("You are printing: julia c(%s, %s)\n", argv[2], argv[3]);
	ft_printf("Controls:\n");
	ft_printf(" move: Arrow keys / IJKL\n");
	ft_printf(" zoom in / zoom out: Scroll / P/O\n");
	ft_printf(" exit: ESC / Q\n");
}

int	main(int argc, char **argv)
{
	t_handler	handler;
	t_complex	num;

	validate_input(argc, argv);
	num.a = 0;
	num.b = 0;
	if (argv[1][0] == 'j')
	{
		num.a = ft_atod(argv[2]);
		num.b = ft_atod(argv[3]);
	}
	init_handler(&handler, argv[1][0], num);
	if (!handler.win.win_ptr || !handler.win.mlx_ptr)
		return (1);
	print_controls(argv);
	print_fractal(handler);
	mlx_hook(handler.win.win_ptr, 17, 0, exit_window, &handler);
	mlx_hook(handler.win.win_ptr, 2, 0, key_press, &handler);
	mlx_hook(handler.win.win_ptr, 4, 0, scroll, &handler);
	mlx_loop(handler.win.mlx_ptr);
	return (0);
}
