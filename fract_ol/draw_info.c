/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:41:20 by mvann             #+#    #+#             */
/*   Updated: 2018/03/08 16:27:15 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_info3(t_env *env, int i)
{
	char	*str;

	str = ft_itoa(env->iterations);
	mlx_string_put(env->mlx, env->win, VALS_LEFT, i++ * INFO_Y_SPACING,
		INFO_COLOR, str);
	mlx_string_put(env->mlx, env->win, INFO_LEFT, i * INFO_Y_SPACING,
		INFO_COLOR, "SCALE ~:");
	free(str);
	str = ft_itoa((int)env->scale);
	mlx_string_put(env->mlx, env->win, VALS_LEFT, i++ * INFO_Y_SPACING,
		INFO_COLOR, str);
	free(str);
	mlx_string_put(env->mlx, env->win, INFO_LEFT, i++ * INFO_Y_SPACING,
		INFO_COLOR, env->lock ? "JULIA LOCKED" : "JULIA UNLOCKED");
	mlx_string_put(env->mlx, env->win, INFO_LEFT, i++ * INFO_Y_SPACING,
		INFO_COLOR, env->zoom_type ?
		"ZOOM: FOLLOW MOUSE" : "ZOOM: CLICK TO SET");
}

void	draw_info2(t_env *env)
{
	int		i;
	char	*fractals[NUM_FRACTALS];

	fractals[0] = "Mandelbrot";
	fractals[1] = "Julia";
	fractals[2] = "Burning Ship";
	i = 0;
	mlx_string_put(env->mlx, env->win, INFO_LEFT, i++ * INFO_Y_SPACING,
		INFO_COLOR, "L to Lock Julia, R to reset, ESC to quit.");
	mlx_string_put(env->mlx, env->win, INFO_LEFT, i++ * INFO_Y_SPACING,
		INFO_COLOR, "<- & -> to change iterations, WASD to shift.");
	mlx_string_put(env->mlx, env->win, INFO_LEFT, i++ * INFO_Y_SPACING,
		INFO_COLOR, "Z to change zoom mode, G to glow.");
	mlx_string_put(env->mlx, env->win, INFO_LEFT, i++ * INFO_Y_SPACING,
		INFO_COLOR, "F to change fractal, C to change color.");
	mlx_string_put(env->mlx, env->win, INFO_LEFT, i * INFO_Y_SPACING,
		INFO_COLOR, "FRACTAL:");
	mlx_string_put(env->mlx, env->win, VALS_LEFT, i++ * INFO_Y_SPACING,
		INFO_COLOR, fractals[env->fractal]);
	mlx_string_put(env->mlx, env->win, INFO_LEFT, i * INFO_Y_SPACING,
		INFO_COLOR, "ITERATIONS:");
	draw_info3(env, i);
}

void	draw_info(t_env *env)
{
	draw_info2(env);
}
