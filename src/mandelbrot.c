/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:02:05 by rprasopk          #+#    #+#             */
/*   Updated: 2026/03/10 21:18:16 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static int	calculate_fractal(double zr, double zi, double cr, double ci)
{
	int		i;
	double	tmp_zr;

	i = 0;
	while ((zr * zr + zi * zi) <= 4.0 && i < MAX_ITER)
	{
		tmp_zr = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp_zr;
		i++;
	}
	return (i);
}

static double	map(double unscaled, double new_min,
		double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled / old_max) + new_min);
}

static void	handle_pixel(t_fractal *fractal, int x, int y)
{
	double	pr;
	double	pi;
	int		iter;
	int		color;

	pr = (map(x, -2.0, 2.0, WIDTH) * fractal->zoom) + fractal->shift_x;
	pi = (map(y, -2.0, 2.0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
		iter = calculate_fractal(pr, pi, fractal->julia_x, fractal->julia_y);
	else
		iter = calculate_fractal(0.0, 0.0, pr, pi);
	if (iter == MAX_ITER)
		color = get_rgba(0, 0, 0, 255);
	else
	{
		color = get_rgba((iter * 255 / MAX_ITER),
				(iter * 255 / MAX_ITER) * 5,
				(iter * 255 / MAX_ITER) * 20,
				255);
	}
	mlx_put_pixel(fractal->img, x, y, color);
}

void	render_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
}
