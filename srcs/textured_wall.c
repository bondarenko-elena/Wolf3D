/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:57 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:38:26 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	textured_wall(t_env *env, int x)
{
	int i;

	i = env->ray->start;
	while (i++ < env->ray->end)
	{
		if (env->ray->side_of_the_world == 0)
		{
			define_color1(env, env->ray->step_x, i);
		}
		else if (env->ray->side_of_the_world == 1)
		{
			define_color2(env, env->ray->step_y, i);
			if (env->ray->side_of_the_world == 1)
				env->ray->color = (env->ray->color >> 1) & 8355711;
		}
		if (x >= 0 && i >= 0 && x < SCREEN_WIDTH && i < SCREEN_HEIGHT)
			env->mlx->adress[(i * SCREEN_WIDTH + x)] = env->ray->color;
	}
}
