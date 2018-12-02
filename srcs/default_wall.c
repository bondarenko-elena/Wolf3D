/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:49 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:44:00 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	default_wall(t_env *env, int x)
{
	int i;

	i = env->ray->start;
	while (i++ < env->ray->end)
	{
		if (env->ray->side_of_the_world == 0)
		{
			if (env->ray->step_x < 0)
				env->ray->color = add_smog(env->color_1, env->ray->perp_wall_d);
			else
				env->ray->color = add_smog(env->color_2, env->ray->perp_wall_d);
		}
		else if (env->ray->side_of_the_world == 1)
		{
			if (env->ray->step_y < 0)
				env->ray->color = add_smog(env->color_3, env->ray->perp_wall_d);
			else
				env->ray->color = add_smog(env->color_4, env->ray->perp_wall_d);
			if (env->ray->side_of_the_world == 1)
				env->ray->color = (env->ray->color >> 1) & 8355711;
		}
		if (x >= 0 && i >= 0 && x < SCREEN_WIDTH && i < SCREEN_HEIGHT)
			env->mlx->adress[(i * SCREEN_WIDTH + x)] = env->ray->color;
	}
}
