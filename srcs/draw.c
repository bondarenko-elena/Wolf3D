/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:50 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw(t_env *env, int x)
{
	if (env->ray->start < 0)
		env->ray->start = 0;
	env->ray->end = env->ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (env->ray->end >= SCREEN_HEIGHT)
		env->ray->end = SCREEN_HEIGHT - 1;
	if (env->ray->side_of_the_world == 0)
	{
		env->ray->wall = env->ray->pos_y
			+ env->ray->perp_wall_d * env->ray->ray_dir_y;
	}
	else
	{
		env->ray->wall = env->ray->pos_x
			+ env->ray->perp_wall_d * env->ray->ray_dir_x;
	}
	env->ray->wall -= floor((env->ray->wall));
	env->ray->tex_x = (int)(env->ray->wall * (double)TEXTURE_WIDTH);
	if (env->ray->side_of_the_world == 0 && env->ray->ray_dir_x > 0)
		env->ray->tex_x = TEXTURE_WIDTH - env->ray->tex_x - 1;
	if (env->ray->side_of_the_world == 1 && env->ray->ray_dir_y < 0)
		env->ray->tex_x = TEXTURE_WIDTH - env->ray->tex_x - 1;
	if (env->ray->switch_textures == 0)
		default_wall(env, x);
	else if (env->ray->switch_textures == 1)
		textured_wall(env, x);
}
