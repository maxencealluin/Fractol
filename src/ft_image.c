/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:24:17 by malluin           #+#    #+#             */
/*   Updated: 2019/02/25 11:33:18 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				image_init(t_win *mlx)
{
	int bpp;
	int s_l;
	int end;

	if (!(mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT)))
		return (0);
	if (!(mlx->image_str = mlx_get_data_addr(mlx->image_ptr, &bpp, &s_l, &end)))
		return (0);
	return (1);
}

int				refresh_init(t_win *mlx)
{
	if (mlx->mlx_ptr && mlx->image_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image_ptr);
	if (!(image_init(mlx)))
		return (0);
	if (!(refresh_show(mlx)))
		return (0);
	return (1);
}

void			ft_viseur(t_win *mlx)
{
	int i;

	i = 0;
	while (i++ < 19)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 390 + i, 400, 0x000000);
	i = 0;
	while (i++ < 19)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 400, 390 + i, 0x000000);
}

static int		show_ui(t_win *mlx, int color, unsigned long time_frame)
{
	char	*str;

	str = ft_lltoa(time_frame / (CLOCKS_PER_SEC / 1000));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, color,
	"Render time (in ms):");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 220, 10, color, str);
	ft_memdel((void **)&str);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, color,
	"Iterations:");
	str = ft_lltoa(mlx->nb_iter);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 150, 30, color, str);
	ft_memdel((void **)&str);
	if (mlx->lock == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, color,
	"Mouse: On");
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, color,
	"Mouse: Off");
	return (1);
}

int				refresh_show(t_win *mlx)
{
	clock_t start;
	clock_t time_frame;

	start = clock();
	if (!(draw_pthread(mlx)))
		return (0);
	time_frame = clock() - start;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image_ptr, 0, 0);
	if (mlx->ui == 1)
		show_ui(mlx, rgb(255, 255, 255), time_frame);
	ft_viseur(mlx);
	return (1);
}
