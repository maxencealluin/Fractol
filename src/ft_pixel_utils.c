/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:50:07 by malluin           #+#    #+#             */
/*   Updated: 2019/02/13 16:39:53 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	int	r;
	int	g;
	int	b;

	r = (red << 16) & 0xFF0000;
	g = (green << 8) & 0x00FF00;
	b = blue & 0x000FF;
	return (0x000000 | r | g | b);
}

void	place_pixel(t_win *mlx, int u, int v, int color)
{
	int	coord;
	int	red;
	int	blue;
	int	green;

	if (color == 0)
		color = rgb(255, 255, 255);
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = (color) & 0xFF;
	u = ft_imax(u, 0);
	coord = u * 4 + v * WIDTH * 4;
	if (coord < WIDTH * 4 * HEIGHT && coord >= 0 && u < WIDTH)
	{
		(mlx->image_str)[coord] = blue;
		(mlx->image_str)[coord + 1] = green;
		(mlx->image_str)[coord + 2] = red;
	}
}

int		color_fractal_2(t_win *mlx, int i)
{
	int		color;

	if (mlx->palette == 6)
		color = rgb(255 - sin(0.5 * 255 * i / mlx->nb_iter) * 127.0 + 128.0,
		cos(0.5 * 255 * i / mlx->nb_iter + 6.0) * 127.0 + 128.0,
		255 - cos(0.5 * 255 * i / mlx->nb_iter + 8.0) * 127.0 + 128.0);
	else if (mlx->palette == 7)
		color = rgb(255 - sin(0.1 * 255 * i / mlx->nb_iter) * 127.0 + 128.0,
		255 - sin(0.1 * 255 * i / mlx->nb_iter + 2.0) * 127.0 + 128.0,
		255 - sin(0.1 * 255 * i / mlx->nb_iter + 4.0) * 127.0 + 128.0);
	else if (mlx->palette == 8)
		color = rgb(cos(0.8 * 255 * i / mlx->nb_iter) * 127.0 + 128.0,
		255 - cos(0.8 * 255 * i / mlx->nb_iter + 2.0) * 127.0 + 128.0,
		cos(0.8 * 255 * i / mlx->nb_iter + 4.0) * 127.0 + 128.0);
	else if (mlx->palette == 9)
		color = rgb(sin(0.3 * 255 * i / mlx->nb_iter + 4) * 127.0 + 128.0,
		sin(0.3 * 255 * i / mlx->nb_iter + 4) * 127.0 + 128.0,
		sin(0.3 * 255 * i / mlx->nb_iter + 4) * 127.0 + 128.0);
	else
		color = rgb(sin(0.3 * 255 * i / mlx->nb_iter) * 127.0 + 128.0,
		sin(0.3 * 255 * i / mlx->nb_iter + 2.0) * 127.0 + 128.0,
		sin(0.3 * 155 * i / mlx->nb_iter + 4.0) * 127.0 + 128.0);
	return (color);
}

int		color_fractal(t_win *mlx, int i)
{
	int		color;

	if (mlx->palette == 1 || mlx->palette < 0 || mlx->palette > 10)
		color = rgb(sin(0.3 * 255 * i / mlx->nb_iter) * 127.0 + 128.0,
		sin(0.3 * 255 * i / mlx->nb_iter + 2.0) * 127.0 + 128.0,
		sin(0.3 * 255 * i / mlx->nb_iter + 4.0) * 127.0 + 128.0);
	else if (mlx->palette == 2)
		color = rgb(sin(0.6 * 255 * i / mlx->nb_iter) * 127.0 + 58.0,
		sin(0.3 * 255 * i / mlx->nb_iter + 2.0) * 127.0 + 58.0,
		sin(0.3 * 255 * i / mlx->nb_iter + 4.0) * 127.0 + 58.0);
	else if (mlx->palette == 3)
		color = rgb(cos(0.3 * 255 * i / mlx->nb_iter) * 127.0 + 128.0,
		255 - cos(0.3 * 255 * i / mlx->nb_iter + 2.0) * 127.0 + 128.0,
		cos(0.3 * 255 * i / mlx->nb_iter + 4.0) * 127.0 + 128.0);
	else if (mlx->palette == 4)
		color = rgb(cos(0.3 * 255 * i / mlx->nb_iter) * 127.0 + 128.0,
		255 - cos(0.3 * 255 * i / mlx->nb_iter + 2.0) * 127.0 + 128.0,
		255 - cos(0.3 * 255 * i / mlx->nb_iter + 4.0) * 127.0 + 128.0);
	else if (mlx->palette == 5)
		color = rgb(255 - sin(0.3 * 255 * i / mlx->nb_iter) * 127.0 + 128.0,
		cos(0.3 * 255 * i / mlx->nb_iter + 2.0) * 127.0 + 128.0,
		255 - cos(0.3 * 255 * i / mlx->nb_iter + 4.0) * 127.0 + 128.0);
	else
		return (color_fractal_2(mlx, i));
	return (color);
}
