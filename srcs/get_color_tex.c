/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:51 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		get_color_tex(t_env *env, int y, int t)
{
	env->ray->d = y * env->size_line[t] - SCREEN_HEIGHT
		* 128 + env->ray->line_height * 128;
	env->ray->tex_y = ((env->ray->d * TEXTURE_HEIGHT)
		/ env->ray->line_height) / env->size_line[t];
	env->color->red = env->data[t][(env->size_line[t]
		* env->ray->tex_y + env->ray->tex_x * 4) + 2];
	env->color->green = env->data[t][(env->size_line[t]
		* env->ray->tex_y + env->ray->tex_x * 4) + 1];
	env->color->blue = env->data[t][env->size_line[t]
		* env->ray->tex_y + env->ray->tex_x * 4];
	env->ray->color = ((env->color->red & 0xff) << 16)
		+ ((env->color->green & 0xff) << 8) + (env->color->blue & 0xff);
	env->ray->color = (env->ray->color >> 1) & 8355711;
	return (env->ray->color);
}
