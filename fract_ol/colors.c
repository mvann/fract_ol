/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:15:38 by mvann             #+#    #+#             */
/*   Updated: 2018/03/08 16:15:24 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	color_grayscale(t_env *env)
{
	int i;

	env->numcolors = 50;
	i = 0;
	while (i < env->numcolors)
	{
		env->colors[i] = i * 3;
		env->colors[i] |= (i * 3) << 8;
		env->colors[i] |= (i * 3) << 16;
		i++;
	}
}

void	color_gradient(t_env *env, int r, int g, int b)
{
	int i;

	env->numcolors = 50;
	i = 0;
	while (i < env->numcolors)
	{
		env->colors[i] = i * 3 * r;
		env->colors[i] |= (i * 3 * g) << 8;
		env->colors[i] |= (i * 3 * b) << 16;
		i++;
	}
}

void	color_ultra(t_env *env)
{
	env->colors[0] = (66 << 16) + (30 << 8) + 15;
	env->colors[1] = (25 << 16) + (7 << 8) + 26;
	env->colors[2] = (9 << 16) + (1 << 8) + 47;
	env->colors[3] = (4 << 16) + (4 << 8) + 73;
	env->colors[4] = (0 << 16) + (7 << 8) + 100;
	env->colors[5] = (12 << 16) + (44 << 8) + 138;
	env->colors[6] = (24 << 16) + (82 << 8) + 177;
	env->colors[7] = (57 << 16) + (125 << 8) + 209;
	env->colors[8] = (134 << 16) + (181 << 8) + 229;
	env->colors[9] = (211 << 16) + (236 << 8) + 248;
	env->colors[10] = (241 << 16) + (233 << 8) + 191;
	env->colors[11] = (248 << 16) + (201 << 8) + 95;
	env->colors[12] = (255 << 16) + (170 << 8) + 0;
	env->colors[13] = (204 << 16) + (128 << 8) + 0;
	env->colors[14] = (153 << 16) + (87 << 8) + 0;
	env->colors[15] = (106 << 16) + (52 << 8) + 3;
	env->numcolors = 16;
}

void	change_color(t_env *env)
{
	env->color_index++;
	if (env->color_index == 0)
		color_grayscale(env);
	else if (env->color_index == 1)
		color_ultra(env);
	else if (env->color_index == 2)
		color_gradient(env, 1, 0, 0);
	else if (env->color_index == 3)
		color_gradient(env, 0, 1, 0);
	else if (env->color_index == 4)
		color_gradient(env, 0, 0, 1);
	else if (env->color_index == 5)
		color_gradient(env, 0, 1, 1);
	else if (env->color_index == 6)
		color_gradient(env, 1, 0, 1);
	else if (env->color_index == 7)
		color_gradient(env, 1, 1, 0);
	else
	{
		env->color_index = -1;
		change_color(env);
	}
}
