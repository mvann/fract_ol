/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:39:44 by mvann             #+#    #+#             */
/*   Updated: 2018/01/19 10:42:54 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	reset_screen(t_env *env)
{
	env->scale = DEFAULT_SCALE;
	env->old_scale = DEFAULT_SCALE;
	env->x_offset = DEFAULT_OFFSET;
	env->y_offset = DEFAULT_OFFSET;
	env->iterations = DEFAULT_ITERATIONS;
}

void	zoom(t_env *env, double scale_scale)
{
	double	delta_scale;

	env->old_scale = env->scale;
	env->scale *= scale_scale;
	delta_scale = env->old_scale - env->scale;
	env->x_offset += ((double)env->zoom_x) / WIN_SIDE * delta_scale;
	env->y_offset += ((double)env->zoom_y) / WIN_SIDE * delta_scale;
}

double	screen_to_plane(double x_or_y, double scale, double off_set)
{
	return (x_or_y * (scale / WIN_SIDE) + off_set);
}

void	shift_iterations(t_env *env, int shift_amount)
{
	env->iterations += shift_amount;
	if (env->iterations < MIN_ITERATIONS)
		env->iterations = MIN_ITERATIONS;
}
