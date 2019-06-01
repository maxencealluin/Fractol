/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:10:10 by malluin           #+#    #+#             */
/*   Updated: 2019/02/22 15:27:48 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_win *mlx)
{
	mlx->nb_iter = 50;
	mlx->x1 = -2.1;
	mlx->x2 = 0.6;
	mlx->y1 = -1.2;
	mlx->y2 = 1.2;
	mlx->gapx = (mlx->x2 - mlx->x1) / 2;
	mlx->gapy = (mlx->y2 - mlx->y1) / 2;
	mlx->zoom_x = WIDTH / (mlx->x2 - mlx->x1);
	mlx->zoom_y = HEIGHT / (mlx->y2 - mlx->y1);
	mlx->cr = 0;
	mlx->ci = 0;
}

void	julia(t_win *mlx)
{
	mlx->nb_iter = 100;
	mlx->x1 = -1;
	mlx->x2 = 1;
	mlx->y1 = -1.2;
	mlx->y2 = 1.2;
	mlx->gapx = (mlx->x2 - mlx->x1) / 2;
	mlx->gapy = (mlx->y2 - mlx->y1) / 2;
	mlx->zoom_x = WIDTH / (mlx->x2 - mlx->x1);
	mlx->zoom_y = HEIGHT / (mlx->y2 - mlx->y1);
	mlx->cr = 0.285;
	mlx->ci = 0.01;
}

void	douady(t_win *mlx)
{
	mlx->nb_iter = 100;
	mlx->x1 = -1.4;
	mlx->x2 = 1.4;
	mlx->y1 = -1.2;
	mlx->y2 = 1.2;
	mlx->gapx = (mlx->x2 - mlx->x1) / 2;
	mlx->gapy = (mlx->y2 - mlx->y1) / 2;
	mlx->zoom_x = WIDTH / (mlx->x2 - mlx->x1);
	mlx->zoom_y = HEIGHT / (mlx->y2 - mlx->y1);
	mlx->cr = -0.123;
	mlx->ci = 0.745;
	mlx->lock = 0;
}

void	burning_ship(t_win *mlx)
{
	mlx->nb_iter = 50;
	mlx->x1 = -2.0;
	mlx->x2 = 1.2;
	mlx->y1 = -1.6;
	mlx->y2 = 1.0;
	mlx->gapx = (mlx->x2 - mlx->x1) / 2;
	mlx->gapy = (mlx->y2 - mlx->y1) / 2;
	mlx->zoom_x = WIDTH / (mlx->x2 - mlx->x1);
	mlx->zoom_y = HEIGHT / (mlx->y2 - mlx->y1);
	mlx->cr = 0;
	mlx->ci = 0;
}

void	burning_julia(t_win *mlx)
{
	mlx->nb_iter = 100;
	mlx->x1 = -1;
	mlx->x2 = 1;
	mlx->y1 = -1.2;
	mlx->y2 = 1.2;
	mlx->gapx = (mlx->x2 - mlx->x1) / 2;
	mlx->gapy = (mlx->y2 - mlx->y1) / 2;
	mlx->zoom_x = WIDTH / (mlx->x2 - mlx->x1);
	mlx->zoom_y = HEIGHT / (mlx->y2 - mlx->y1);
	mlx->cr = 0.285;
	mlx->ci = 0.01;
}
