/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:47:37 by malluin           #+#    #+#             */
/*   Updated: 2019/02/22 15:29:39 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_mlx(t_win *mlx)
{
	if (!mlx)
		return ;
	if (mlx->mlx_ptr && mlx->image_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_memdel((void **)mlx);
}

void	ft_exit(t_win *mlx)
{
	ft_free_mlx(mlx);
	exit(1);
}

void	ft_usage(void)
{
	write(1,
		"./fractol [mandelbrot/julia/douady/burning_ship/burning_julia]\n", 63);
	exit(-1);
}
