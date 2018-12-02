/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:51 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:43:17 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_env	*init_env(t_env *env)
{
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		malloc_error();
	env->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!env->ray)
		malloc_error();
	env->color = (t_color *)malloc(sizeof(t_color));
	if (!env->color)
		malloc_error();
	env->ray->pos_x = 1.5;
	env->ray->pos_y = 1.5;
	env->ray->dir_x = 1;
	env->ray->dir_y = 0;
	env->ray->plane_x = 0;
	env->ray->plane_y = 0.66;
	env->ray->switch_textures = 0;
	env->ray->music_tumbler = 0;
	env->color_1 = 0x0000ff;
	env->color_2 = 0xff0000;
	env->color_3 = 0x00ffff;
	env->color_4 = 0x00ff00;
	return (env);
}
