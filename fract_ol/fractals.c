/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:38:18 by mvann             #+#    #+#             */
/*   Updated: 2018/01/17 14:52:39 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		mandelbrot(double r, double i, int iterations)
{
	t_cnum	z;
	double	zrsqr;
	double	zisqr;
	int		count;

	z.r = 0;
	z.i = 0;
	zrsqr = z.r * z.r;
	zisqr = z.i * z.i;
	count = 0;
	while (zrsqr + zisqr <= 4.0 && count < iterations)
	{
		count++;
		z.i = (z.r + z.i) * (z.r + z.i) - zrsqr - zisqr;
		z.i += i;
		z.r = zrsqr - zisqr + r;
		zrsqr = z.r * z.r;
		zisqr = z.i * z.i;
	}
	return (count == iterations ? -1 : count);
}

int		burning_ship(double r, double i, int iterations)
{
	t_cnum	z;
	double	zrsqr;
	double	zisqr;
	int		count;

	z.r = 0;
	z.i = 0;
	zrsqr = z.r * z.r;
	zisqr = z.i * z.i;
	count = 0;
	while (zrsqr + zisqr <= 4.0 && count < iterations)
	{
		count++;
		z.i = (z.r + z.i) * (z.r + z.i) - zrsqr - zisqr;
		z.i += i;
		z.i = fabs(z.i);
		z.r = fabs(zrsqr - zisqr + r);
		zrsqr = z.r * z.r;
		zisqr = z.i * z.i;
	}
	return (count == iterations ? -1 : count);
}

int		julia(t_env *env, double r, double i, int iterations)
{
	t_cnum	z;
	double	zrsqr;
	double	zisqr;
	int		count;

	z.r = r;
	z.i = i;
	zrsqr = z.r * z.r;
	zisqr = z.i * z.i;
	count = 0;
	while (zrsqr + zisqr <= 4.0 && count < iterations)
	{
		count++;
		z.i = (z.r + z.i) * (z.r + z.i) - zrsqr - zisqr;
		z.i += (double)env->mouse_y / WIN_SIDE * 4 - 2;
		z.r = zrsqr - zisqr + (double)env->mouse_x / WIN_SIDE * 4 - 2;
		zrsqr = z.r * z.r;
		zisqr = z.i * z.i;
	}
	return (count == iterations ? -1 : count);
}
