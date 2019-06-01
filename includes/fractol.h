/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:22:25 by malluin           #+#    #+#             */
/*   Updated: 2019/02/13 15:49:52 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>
# include <stdio.h>

typedef struct		s_fract {
	double			zr;
	double			zi;
	int				i;
	double			tmp;
	double			cr;
	double			ci;
}					t_fract;

typedef struct		s_draw {
	int				x;
	int				y;
	int				i;
	int				limit;
}					t_draw;

typedef	struct		s_win {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
	char			*image_str;
	int				palette;
	int				fractal;
	int				pthread;
	int				ui;
	double			zoom_coef;
	float			scale;
	long			zoom_x;
	long			zoom_y;
	int				nb_iter;
	int				lock;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	double			gapx;
	double			gapy;
	double			cr;
	double			ci;
	pthread_mutex_t mutex_stock;
}					t_win;

int					draw_pthread(t_win *mlx);

void				reset_fractal(t_win *mlx);
void				mandelbrot(t_win *mlx);
void				julia(t_win *mlx);
void				douady(t_win *mlx);
void				burning_ship(t_win *mlx);
void				burning_julia(t_win *mlx);

int					ft_close(void *param);
void				ft_exit(t_win *mlx);
void				ft_usage(void);

int					color_fractal(t_win *mlx, int i);
int					color_fractal_2(t_win *mlx, int i);

int					refresh_init(t_win *mlx);
int					refresh_show(t_win *mlx);
void				place_pixel(t_win *mlx, int x, int y, int color);
int					rgb(unsigned char red, unsigned char green,
					unsigned char blue);
int					deal_key(int key, void *param);
int					mouse(int button, int x, int y, void *param);
int					mouse_julia(int x, int y, void *param);
#endif
