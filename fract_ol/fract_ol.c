/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:25:49 by mvann             #+#    #+#             */
/*   Updated: 2018/03/08 15:59:21 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		check_arguments(int ac, char **av)
{
	if (ac != 1 || (ft_strcmp(av[0], "mandelbrot") &&
		ft_strcmp(av[0], "julia") &&
		ft_strcmp(av[0], "burning") &&
		ft_strcmp(av[0], "burning ship")))
	{
		ft_putstr("Enter 'mandelbrot', 'julia', or 'burning ship'.\n");
		exit(EXIT_SUCCESS);
	}
}

void		error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

int			get_fractal_num(char **av)
{
	if (!ft_strcmp(av[0], "mandelbrot"))
		return (MANDELBROT);
	else if (!ft_strcmp(av[0], "julia"))
		return (JULIA);
	return (BURNING_SHIP);
}

static void	init_env(t_env **env, char **av)
{
	t_env *e;

	if (!(*env = (t_env *)ft_memalloc(sizeof(t_env)))
	|| !((*env)->mlx = mlx_init()))
		error();
	e = *env;
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fract_ol");
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->colors = ft_memalloc(sizeof(int) * MAX_COLORS);
	if (!(e->win) || !(e->img) || !(e->colors))
		error();
	e->buff = (int *)mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->end));
	e->iterations = DEFAULT_ITERATIONS;
	e->fractal = get_fractal_num(av);
	e->lock = 0;
	e->color_index = 0;
	e->scale = DEFAULT_SCALE;
	e->old_scale = DEFAULT_SCALE;
	e->x_offset = DEFAULT_OFFSET;
	e->y_offset = DEFAULT_OFFSET;
	e->zoom_x = WIN_SIDE / 2;
	e->zoom_y = WIN_SIDE / 2;
	e->mouse_x = WIN_SIDE / 2;
	e->mouse_y = WIN_SIDE / 2;
	change_color(e);
}

int			main(int ac, char **av)
{
	t_env *env;

	ac--;
	av++;
	check_arguments(ac, av);
	init_env(&env, av);
	env->zoom_type = 0;
	env->glow = -1;
	mlx_hook(env->win, 2, 0, keydown_event, env);
	mlx_hook(env->win, 3, 0, keyup_event, env);
	mlx_hook(env->win, 6, 0, motion_event, env);
	mlx_mouse_hook(env->win, mouse_event, env);
	mlx_loop_hook(env->mlx, loop_event, env);
	run(env);
	mlx_loop(env->mlx);
	return (0);
}
