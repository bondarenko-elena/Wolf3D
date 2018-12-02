/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:50 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:49:31 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	do_magic(t_env *env)
{
	if (env->ray->map[(int)env->ray->pos_x][(int)env->ray->pos_y] != 0)
		map_error();
	init_textures(env);
	ray_casting(env);
	mlx_put_image_to_window(env->mlx->mlx_init,
		env->mlx->window, env->mlx->image, 0, 0);
	display_text(env);
	mlx_hook(env->mlx->window, 2, 1L << 0, key_press, env);
	mlx_hook(env->mlx->window, 3, 1L << 0, key_release, env);
	mlx_loop_hook(env->mlx->mlx_init, moves, env);
	mlx_hook(env->mlx->window, 17, 1L << 0, red_cross, env);
	mlx_loop(env->mlx->mlx_init);
}
