/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:50:11 by malluin           #+#    #+#             */
/*   Updated: 2019/02/13 14:20:19 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_win *mlx, int x, int y)
{
	double			perx;
	double			pery;

	perx = x / (double)WIDTH;
	pery = y / (double)HEIGHT;
	mlx->zoom_x *= 1.25;
	mlx->zoom_y *= 1.25;
	mlx->nb_iter += mlx->nb_iter + 20 <= 1500 ? 20 : 0;
	if (mlx->zoom_x != 0 && mlx->zoom_y != 0)
	{
		mlx->x1 += 100.0 * (perx - 0.5) / mlx->zoom_x * 2;
		mlx->x2 += 100.0 * (perx - 0.5) / mlx->zoom_x * 2;
		mlx->y1 += 100.0 * (pery - 0.5) / mlx->zoom_y * 2;
		mlx->y2 += 100.0 * (pery - 0.5) / mlx->zoom_y * 2;
	}
	mlx->x1 += (mlx->zoom_coef) * mlx->gapx;
	mlx->x2 += (mlx->zoom_coef) * mlx->gapx;
	mlx->y1 += (mlx->zoom_coef) * mlx->gapy;
	mlx->y2 += (mlx->zoom_coef) * mlx->gapy;
	(mlx->zoom_coef) *= 0.8;
}

static void	dezoom(t_win *mlx, int x, int y)
{
	double			perx;
	double			pery;

	perx = x / (double)WIDTH;
	pery = y / (double)HEIGHT;
	mlx->zoom_x /= 1.25;
	mlx->zoom_y /= 1.25;
	mlx->nb_iter += mlx->nb_iter - 20 <= 100 ? 0 : -10;
	if (mlx->zoom_x != 0 && mlx->zoom_y != 0)
	{
		mlx->x1 -= 100.0 * (perx - 0.5) / mlx->zoom_x * 2;
		mlx->x2 -= 100.0 * (perx - 0.5) / mlx->zoom_x * 2;
		mlx->y1 -= 100.0 * (pery - 0.5) / mlx->zoom_y * 2;
		mlx->y2 -= 100.0 * (pery - 0.5) / mlx->zoom_y * 2;
	}
	mlx->x1 -= (mlx->zoom_coef) * mlx->gapx;
	mlx->x2 -= (mlx->zoom_coef) * mlx->gapx;
	mlx->y1 -= (mlx->zoom_coef) * mlx->gapy;
	mlx->y2 -= (mlx->zoom_coef) * mlx->gapy;
	(mlx->zoom_coef) /= 0.8;
}

int			mouse(int button, int x, int y, void *param)
{
	t_win			*mlx;

	mlx = (t_win *)param;
	if (button == 5)
		zoom(mlx, x, y);
	else if (button == 4)
		dezoom(mlx, x, y);
	refresh_init(mlx);
	return (0);
}

int			mouse_julia(int x, int y, void *param)
{
	t_win	*mlx;
	double	cr;
	double	ci;

	mlx = (t_win *)param;
	if (mlx->fractal == 1 || mlx->lock == 0)
		return (0);
	if (mlx->fractal == 2)
	{
		cr = 0.285;
		ci = 0.01;
	}
	else
	{
		cr = -0.123;
		ci = 0.745;
	}
	if (mlx->lock == 1)
	{
		mlx->cr = cr + 0.01 * (x - WIDTH / 2);
		mlx->ci = ci + 0.01 * (y - HEIGHT / 2);
	}
	refresh_init(mlx);
	return (0);
}
