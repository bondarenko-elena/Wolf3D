/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:53 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		move_down(t_env *env)
{
	if (env->ray->map[(int)(env->ray->pos_x - env->ray->dir_x * 0.4)]
			[(int)(env->ray->pos_y)] == 0)
	{
		env->ray->pos_x -= env->ray->dir_x * 0.1;
	}
	if (env->ray->map[(int)(env->ray->pos_x)]
		[(int)(env->ray->pos_y - env->ray->dir_y * 0.4)] == 0)
	{
		env->ray->pos_y -= env->ray->dir_y * 0.1;
	}
}
