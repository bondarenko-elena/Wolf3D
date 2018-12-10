/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:11 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	calculate_distance(t_env *env)
{
	while (env->ray->hit == 0)
	{
		if (env->ray->side_dist_x < env->ray->side_dist_y)
		{
			env->ray->side_dist_x += env->ray->delta_dist_x;
			env->ray->map_x += env->ray->step_x;
			env->ray->side_of_the_world = 0;
		}
		else
		{
			env->ray->side_dist_y += env->ray->delta_dist_y;
			env->ray->map_y += env->ray->step_y;
			env->ray->side_of_the_world = 1;
		}
		if (env->ray->map[env->ray->map_x][env->ray->map_y] > 0)
			env->ray->hit = 1;
	}
	if (env->ray->side_of_the_world == 0)
		env->ray->perp_wall_d = (env->ray->map_x -
			env->ray->pos_x + (1 - env->ray->step_x) / 2) / env->ray->ray_dir_x;
	else
		env->ray->perp_wall_d = (env->ray->map_y -
			env->ray->pos_y + (1 - env->ray->step_y) / 2) / env->ray->ray_dir_y;
	env->ray->line_height = (int)(SCREEN_HEIGHT / env->ray->perp_wall_d);
	env->ray->start = -env->ray->line_height / 2 + SCREEN_HEIGHT / 2;
}
