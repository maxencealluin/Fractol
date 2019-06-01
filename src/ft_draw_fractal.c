/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:45:25 by malluin           #+#    #+#             */
/*   Updated: 2019/02/13 10:46:11 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iterate_pixel(t_win *mlx, int x, int y, int nb_iter)
{
	t_fract	fract;

	fract.i = 0;
	fract.zr = 0;
	fract.zi = 0;
	if (mlx->fractal == 1)
	{
		fract.cr = (double)x / (double)mlx->zoom_x + mlx->x1;
		fract.ci = (double)y / (double)mlx->zoom_y + mlx->y1;
	}
	else if (mlx->fractal >= 2)
	{
		fract.zr = (double)x / (double)mlx->zoom_x + mlx->x1;
		fract.zi = (double)y / (double)mlx->zoom_y + mlx->y1;
		fract.cr = mlx->cr;
		fract.ci = mlx->ci;
	}
	while (fract.i < nb_iter && (fract.zr * fract.zr + fract.zi * fract.zi) < 4)
	{
		fract.tmp = fract.zr;
		fract.zr = fract.zr * fract.zr - fract.zi * fract.zi + fract.cr;
		fract.zi = 2 * fract.tmp * fract.zi + fract.ci;
		fract.i++;
	}
	return (fract.i);
}

static int		iterate_pixel_ship(t_win *mlx, int x, int y, int nb_iter)
{
	t_fract	fract;

	fract.i = 0;
	if (mlx->fractal == 4)
	{
		fract.zr = fract.cr;
		fract.zi = fract.ci;
		fract.cr = (double)x / (double)mlx->zoom_x + mlx->x1;
		fract.ci = (double)y / (double)mlx->zoom_y + mlx->y1;
	}
	else if (mlx->fractal == 5)
	{
		fract.zr = (double)x / (double)mlx->zoom_x + mlx->x1;
		fract.zi = (double)y / (double)mlx->zoom_y + mlx->y1;
		fract.cr = mlx->cr;
		fract.ci = mlx->ci;
	}
	while (fract.i < nb_iter && (fract.zr * fract.zr + fract.zi * fract.zi) < 4)
	{
		fract.tmp = fract.zr * fract.zr - fract.zi * fract.zi + fract.cr;
		fract.zi = ft_lfabs(2 * fract.zr * fract.zi) + fract.ci;
		fract.zr = ft_lfabs(fract.tmp);
		fract.i++;
	}
	return (fract.i);
}

static void		*draw_fractal(void *mlx_void)
{
	static pthread_mutex_t	mutex_stock = PTHREAD_MUTEX_INITIALIZER;
	static int				v = -1;
	t_draw					draw;
	t_win					*mlx;

	mlx = (t_win *)mlx_void;
	pthread_mutex_lock(&mutex_stock);
	v = (v + 1) % mlx->pthread;
	draw.y = HEIGHT / mlx->pthread * v - 1;
	draw.limit = v;
	pthread_mutex_unlock(&mutex_stock);
	while (++draw.y < HEIGHT / mlx->pthread * (draw.limit + 1))
	{
		draw.x = -1;
		while (++draw.x < WIDTH)
		{
			draw.i = mlx->fractal >= 4 ? iterate_pixel_ship(mlx, draw.x, draw.y,
			mlx->nb_iter) : iterate_pixel(mlx, draw.x, draw.y, mlx->nb_iter);
			if (draw.i == mlx->nb_iter)
				place_pixel(mlx, draw.x, draw.y, color_fractal(mlx, draw.i));
			else
				place_pixel(mlx, draw.x, draw.y, color_fractal(mlx, draw.i));
		}
	}
	pthread_exit(NULL);
}

int				draw_pthread(t_win *mlx)
{
	pthread_t	thread[8];
	int			i;

	i = 0;
	mlx->pthread = 8;
	while (i < mlx->pthread)
		if (pthread_create(&thread[i++], NULL, draw_fractal,
			(void *)(mlx)) == -1)
			perror("thread creation");
	i = 0;
	while (i < mlx->pthread)
		if (pthread_join(thread[i++], NULL) == -1)
			perror("thread join");
	return (1);
}
