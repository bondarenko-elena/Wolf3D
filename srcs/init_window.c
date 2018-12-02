/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:52 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:41:59 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_window(t_env *env)
{
	if (!check_walls_exist(env->ray))
		map_error();
	env->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	env->mlx->mlx_init = mlx_init();
	env->mlx->window = mlx_new_window(env->mlx->mlx_init, SCREEN_WIDTH,
			SCREEN_HEIGHT, "wolf3d@olbondar");
	env->mlx->image = mlx_new_image(env->mlx->mlx_init, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	env->mlx->adress = (int *)mlx_get_data_addr(env->mlx->image,
				&env->mlx->endian, &env->mlx->size_line,
				&env->mlx->bits_per_pixel);
	mlx_put_image_to_window(env->mlx->mlx_init, env->mlx->window,
				env->mlx->image, 0, 0);
}
