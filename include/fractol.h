/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 01:39:12 by rprasopk          #+#    #+#             */
/*   Updated: 2026/03/10 21:18:12 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		zoom;
	double		shift_x;
	double		shift_y;
	char		*name;
	double		julia_x;
	double		julia_y;
}	t_fractal;

void	render_fractal(t_fractal *fractal);
void	ft_putstr(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atof(const char *str);

#endif
