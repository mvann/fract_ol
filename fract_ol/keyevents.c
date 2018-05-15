/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevents.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:56:10 by mvann             #+#    #+#             */
/*   Updated: 2018/03/08 16:16:57 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	keydown_event2(int keycode, t_env *env)
{
	if (keycode == KEY_C)
		change_color(env);
	else if (keycode == KEY_Z)
		env->zoom_type = !(env->zoom_type);
	else if (keycode == KEY_G)
	{
		if (env->glow < 0)
			env->glow = 0;
		else
			env->glow = -1;
	}
}

int		keydown_event(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_LEFT)
		shift_iterations(env, -10);
	else if (keycode == KEY_RIGHT)
		shift_iterations(env, 10);
	else if (keycode == KEY_F)
		env->fractal = (env->fractal + 1) % NUM_FRACTALS;
	else if (keycode == KEY_L)
		env->lock = !env->lock;
	else if (keycode == KEY_W)
		env->y_offset -= env->scale / 20;
	else if (keycode == KEY_A)
		env->x_offset -= env->scale / 10;
	else if (keycode == KEY_S)
		env->y_offset += env->scale / 10;
	else if (keycode == KEY_D)
		env->x_offset += env->scale / 10;
	else if (keycode == KEY_R)
		reset_screen(env);
	else
		keydown_event2(keycode, env);
	run(env);
	return (0);
}

int		keyup_event(int keycode, t_env *env)
{
	(void)env;
	keycode++;
	run(env);
	return (0);
}

int		mouse_event(int button, int x, int y, t_env *env)
{
	if (button == CLICK)
	{
		env->zoom_x = x;
		env->zoom_y = y;
	}
	else if (button == SCROLL_UP)
		zoom(env, 1.25);
	else if (button == SCROLL_DOWN)
		zoom(env, .8);
	run(env);
	return (0);
}

int		motion_event(int x, int y, t_env *env)
{
	if (!env->lock)
	{
		env->mouse_x = x;
		env->mouse_y = y;
	}
	if (env->zoom_type)
	{
		env->zoom_x = x;
		env->zoom_y = y;
	}
	run(env);
	return (0);
}
