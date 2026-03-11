/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 01:45:41 by rprasopk          #+#    #+#             */
/*   Updated: 2026/03/08 05:26:37 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractal->mlx);
	if (keydata.key == MLX_KEY_UP
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		fractal->shift_y -= (0.5 * fractal->zoom);
	if (keydata.key == MLX_KEY_DOWN
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		fractal->shift_y += (0.5 * fractal->zoom);
	if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		fractal->shift_x -= (0.5 * fractal->zoom);
	if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		fractal->shift_x += (0.5 * fractal->zoom);
	render_fractal(fractal);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	(void)xdelta;
	fractal = param;
	if (ydelta > 0)
		fractal->zoom *= 0.95;
	else if (ydelta < 0)
		fractal->zoom *= 1.05;
	render_fractal(fractal);
}

static void	check_input(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
	{
		fractal->name = argv[1];
		return ;
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		fractal->name = argv[1];
		fractal->julia_x = ft_atof(argv[2]);
		fractal->julia_y = ft_atof(argv[3]);
		return ;
	}
	ft_putstr("Available fractals:\n");
	ft_putstr("./fractol mandelbrot\n");
	ft_putstr("./fractol julia <real> <imaginary>\n");
	exit(EXIT_FAILURE);
}

static void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_terminate(fractal->mlx);
		exit(EXIT_FAILURE);
	}
	fractal->zoom = 1.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	check_input(argc, argv, &fractal);
	init_fractal(&fractal);
	render_fractal(&fractal);
	if (mlx_image_to_window(fractal.mlx, fractal.img, 0, 0) == -1)
	{
		mlx_terminate(fractal.mlx);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(fractal.mlx, my_keyhook, &fractal);
	mlx_scroll_hook(fractal.mlx, my_scrollhook, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
