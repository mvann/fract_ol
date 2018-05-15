/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:25:16 by mvann             #+#    #+#             */
/*   Updated: 2018/03/08 15:56:48 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define WIN_SIDE 1000
# define WIN_X WIN_SIDE
# define WIN_Y WIN_SIDE
# define NUM_THREADS 250

# define INFO_LEFT 30
# define VALS_LEFT 200
# define INFO_Y_SPACING 30
# define INFO_COLOR 0xFFFFFF

# define DEFAULT_OFFSET -2;
# define DEFAULT_SCALE 4.0
# define DEFAULT_ITERATIONS 50
# define MIN_ITERATIONS 1

# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2
# define NUM_FRACTALS 3

# define MAX_COLORS 100

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define CLICK 1
# define SCROLL_DOWN 4
# define SCROLL_UP 5
# define SCROLL_RIGHT 6
# define SCROLL_LEFT 7

typedef struct	s_cnum
{
	float		r;
	float		i;
}				t_cnum;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*buff;
	int			bpp;
	int			sl;
	int			end;
	int			*colors;
	int			numcolors;
	int			color_index;
	int			glow;
	int			fractal;
	int			iterations;
	int			lock;
	double		scale;
	double		old_scale;
	int			mouse_x;
	int			mouse_y;
	int			zoom_x;
	int			zoom_y;
	int			zoom_type;
	double		x_offset;
	double		y_offset;
}				t_env;

typedef struct	s_penv
{
	t_env		*env;
	int			row;
}				t_penv;

int				keydown_event(int keycode, t_env *env);
int				keyup_event(int keycode, t_env *env);
int				mouse_event(int button, int x, int y, t_env *env);
int				motion_event(int x, int y, t_env *env);

void			run(t_env *env);
int				loop_event(t_env *env);

void			draw_info(t_env *env);

void			draw(t_env *env);

int				mandelbrot(double r, double i, int iterations);
int				burning_ship(double r, double i, int iterations);
int				julia(t_env *env, double r, double i, int iterations);

void			color_grayscale(t_env *env);
void			change_color(t_env *env);

void			reset_screen(t_env *env);
void			zoom(t_env *env, double scale_scale);
double			screen_to_plane(double x_or_y, double scale, double off_set);
void			shift_iterations(t_env *env, int shift_amount);

#endif
