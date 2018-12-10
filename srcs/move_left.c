/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:53 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		move_left(t_env *env)
{
	if (env->ray->map[(int)(env->ray->pos_x + env->ray->dir_x * cos(-M)
		- env->ray->dir_y * sin(-M) * 0.4)][(int)env->ray->pos_y] == 0)
	{
		env->ray->pos_x += (env->ray->dir_x * cos(-M) - env->ray->dir_y
			* sin(-M)) * C;
	}
	if (env->ray->map[(int)env->ray->pos_x][(int)(env->ray->pos_y
		+ env->ray->dir_x * sin(-M) * 0.4 + env->ray->dir_y * cos(-M))] == 0)
	{
		env->ray->pos_y += (env->ray->dir_x * sin(-M) + env->ray->dir_y
			* cos(-M)) * C;
	}
}
