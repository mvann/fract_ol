/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:10:05 by mvann             #+#    #+#             */
/*   Updated: 2018/03/08 16:16:37 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		get_escape_number(double r, double i, t_env *env)
{
	if (env->fractal == MANDELBROT)
		return (mandelbrot(r, i, env->iterations));
	if (env->fractal == JULIA)
		return (julia(env, r, i, env->iterations));
	return (burning_ship(r, i, env->iterations));
}

void	draw_pixels(t_env *env, int row)
{
	int		x;
	int		y;
	int		f;
	double	r;
	double	i;

	x = 0;
	while (x < WIN_X)
	{
		y = row;
		while (y < row + 4)
		{
			r = screen_to_plane((double)x, env->scale, env->x_offset);
			i = screen_to_plane((double)y, env->scale, env->y_offset);
			if ((f = get_escape_number(r, i, env)) >= 0)
				env->buff[x + WIN_SIDE * y] = env->colors
				[(f + (env->glow > -1 ? env->glow : 0)) % env->numcolors];
			else
				env->buff[x + WIN_SIDE * y] = 0x000000;
			y++;
		}
		x++;
	}
}

void	*thread_func(void *arg)
{
	t_penv *penv;

	penv = (t_penv *)arg;
	draw_pixels(penv->env, penv->row);
	return (NULL);
}

void	draw(t_env *env)
{
	pthread_t	threads[NUM_THREADS];
	t_penv		penvs[NUM_THREADS];
	int			i;

	mlx_clear_window(env->mlx, env->win);
	i = 0;
	while (i < NUM_THREADS)
	{
		penvs[i].env = env;
		penvs[i].row = i * 4;
		pthread_create(&threads[i], NULL, thread_func, penvs + i);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_pixel_put(env->mlx, env->win, env->zoom_x, env->zoom_y, 0xFF0000);
	draw_info(env);
}
