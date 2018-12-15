/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:54 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ray_init(t_env *env, int x)
{
	env->ray->camera = 2 * x / (double)SCREEN_WIDTH - 1;
	env->ray->ray_dir_x = env->ray->dir_x + env->ray->plane_x
		* env->ray->camera;
	env->ray->ray_dir_y = env->ray->dir_y + env->ray->plane_y
		* env->ray->camera;
	env->ray->map_x = (int)env->ray->pos_x;
	env->ray->map_y = (int)env->ray->pos_y;
	env->ray->delta_dist_x = fabs(1 / env->ray->ray_dir_x);
	env->ray->delta_dist_y = fabs(1 / env->ray->ray_dir_y);
	env->ray->hit = 0;
}
