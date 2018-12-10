/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_step_side.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:30 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	calculate_step_side(t_env *env)
{
	if (env->ray->ray_dir_x < 0)
	{
		env->ray->step_x = -1;
		env->ray->side_dist_x = (env->ray->pos_x - env->ray->map_x)
			* env->ray->delta_dist_x;
	}
	else
	{
		env->ray->step_x = 1;
		env->ray->side_dist_x = (env->ray->map_x + 1.0 - env->ray->pos_x)
			* env->ray->delta_dist_x;
	}
	if (env->ray->ray_dir_y < 0)
	{
		env->ray->step_y = -1;
		env->ray->side_dist_y = (env->ray->pos_y - env->ray->map_y)
			* env->ray->delta_dist_y;
	}
	else
	{
		env->ray->step_y = 1;
		env->ray->side_dist_y = (env->ray->map_y + 1.0 - env->ray->pos_y)
			* env->ray->delta_dist_y;
	}
}
