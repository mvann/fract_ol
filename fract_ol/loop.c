/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:58:41 by mvann             #+#    #+#             */
/*   Updated: 2018/03/08 16:09:47 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	run(t_env *env)
{
	if (env->glow > -1)
		env->glow = (env->glow + 1) % env->numcolors;
	draw(env);
}

int		loop_event(t_env *env)
{
	if (env->glow > -1)
		run(env);
	return (0);
}
