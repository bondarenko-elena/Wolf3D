/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:56 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		rotate_left(t_env *env)
{
	env->ray->old_dir_x = env->ray->dir_x;
	env->ray->dir_x = env->ray->dir_x * cos(-R) - env->ray->dir_y * sin(-R);
	env->ray->dir_y = env->ray->old_dir_x * sin(-R) + env->ray->dir_y * cos(-R);
	env->ray->old_plane_x = env->ray->plane_x;
	env->ray->plane_x = env->ray->plane_x * cos(-R) - env->ray->plane_y
		* sin(-R);
	env->ray->plane_y = env->ray->old_plane_x * sin(-R) + env->ray->plane_y
		* cos(-R);
}
