/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:50:15 by malluin           #+#    #+#             */
/*   Updated: 2019/02/13 13:31:49 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_fractal(t_win *mlx, int key)
{
	if (key == 83)
		mlx->fractal = 1;
	else if (key == 84)
		mlx->fractal = 2;
	else if (key == 85)
		mlx->fractal = 3;
	else if (key == 86)
		mlx->fractal = 4;
	else if (key == 87)
		mlx->fractal = 5;
	else
		return ;
	reset_fractal(mlx);
}

void	change_palette(t_win *mlx, int key)
{
	if (key == 18)
		mlx->palette = 1;
	else if (key == 19)
		mlx->palette = 2;
	else if (key == 20)
		mlx->palette = 3;
	else if (key == 21)
		mlx->palette = 4;
	else if (key == 22)
		mlx->palette = 6;
	else if (key == 23)
		mlx->palette = 5;
	else if (key == 29)
		mlx->palette = 10;
	else if (key == 25)
		mlx->palette = 9;
	else if (key == 26)
		mlx->palette = 7;
	else if (key == 28)
		mlx->palette = 8;
	else
		return ;
}

void	ft_move(t_win *mlx, int key)
{
	if (key == 123)
	{
		mlx->x1 += -60.0 / mlx->zoom_x;
		mlx->x2 += -60.0 / mlx->zoom_x;
	}
	else if (key == 124)
	{
		mlx->x1 += 60.0 / mlx->zoom_x;
		mlx->x2 += 60.0 / mlx->zoom_x;
	}
	else if (key == 125)
	{
		mlx->y1 += 60.0 / mlx->zoom_y;
		mlx->y2 += 60.0 / mlx->zoom_y;
	}
	else if (key == 126)
	{
		mlx->y1 += -60.0 / mlx->zoom_y;
		mlx->y2 += -60.0 / mlx->zoom_y;
	}
}

int		deal_key(int key, void *param)
{
	t_win	*mlx;

	mlx = (t_win *)param;
	if (key == 53)
		ft_exit(mlx);
	else if (key >= 123 && key <= 126)
		ft_move(mlx, key);
	else if (key >= 83 && key <= 92)
		change_fractal(mlx, key);
	else if (key >= 18 && key <= 29)
		change_palette(mlx, key);
	else if (key == 4)
		mlx->ui = mlx->ui != 1;
	else if (key == 78)
		mlx->nb_iter += mlx->nb_iter - 20 <= 0 ? 0 : -20;
	else if (key == 69)
		mlx->nb_iter += mlx->nb_iter + 20 >= 1500 ? 0 : +10;
	else if (key == 49)
		reset_fractal(mlx);
	else if (key == 37)
		mlx->lock = mlx->lock == 1 ? 0 : 1;
	if (!(refresh_init(mlx)))
		return (0);
	return (1);
}
