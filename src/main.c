/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:21:47 by malluin           #+#    #+#             */
/*   Updated: 2019/02/22 15:28:20 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			reset_fractal(t_win *mlx)
{
	mlx->zoom_coef = 0.2;
	if (mlx->fractal == 1)
		mandelbrot(mlx);
	else if (mlx->fractal == 2)
		julia(mlx);
	else if (mlx->fractal == 3)
		douady(mlx);
	else if (mlx->fractal == 4)
		burning_ship(mlx);
	else if (mlx->fractal == 5)
		burning_julia(mlx);
}

static t_win	*initialize(int fractale)
{
	t_win	*mlx;

	if (!(mlx = (t_win *)malloc(sizeof(t_win))))
		return (0);
	if (!(mlx->mlx_ptr = mlx_init()))
		exit(-1);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH,
		HEIGHT + 45, "Fract'ol")))
		exit(-1);
	mlx->image_ptr = NULL;
	mlx->image_str = NULL;
	mlx->palette = 1;
	mlx->fractal = fractale;
	mlx->lock = 0;
	mlx->pthread = 0;
	mlx->ui = 0;
	mlx->zoom_coef = 0.2;
	reset_fractal(mlx);
	return (mlx);
}

static int		ft_check(char *av)
{
	int		fractal;

	fractal = 1;
	if (ft_strcmp(av, "mandelbrot") == 0)
		fractal = 1;
	else if (ft_strcmp(av, "julia") == 0)
		fractal = 2;
	else if (ft_strcmp(av, "douady") == 0)
		fractal = 3;
	else if (ft_strcmp(av, "burning_ship") == 0)
		fractal = 4;
	else if (ft_strcmp(av, "burning_julia") == 0)
		fractal = 5;
	else
		ft_usage();
	return (fractal);
}

int				main(int ac, char **av)
{
	t_win	*mlx;
	int		fractal;

	fractal = 0;
	if (ac != 2)
		ft_usage();
	else if (ac == 2)
		fractal = ft_check(av[1]);
	mlx = initialize(fractal);
	if (!(refresh_init(mlx)))
		return (0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 7, HEIGHT,
		rgb(255, 220, 220), "H: UI On/Off  Pav num 1-5: Change Fractal");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIDTH / 2 + 30, HEIGHT,
		rgb(255, 220, 220), "1-10: Change color  L: Lock/Unlock");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 27, HEIGHT + 20,
		rgb(255, 220, 220),
		"Space: Reset  Scroll: Zoom   +/-: Change iterations   Escape: Close ");
	mlx_hook(mlx->win_ptr, 2, 0, deal_key, (void *)mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse, (void *)mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_julia, (void *)mlx);
	mlx_hook(mlx->win_ptr, 17, 0, ft_close, (void *)mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
