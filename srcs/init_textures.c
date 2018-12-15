/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:59:52 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/19 16:59:53 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_textures(t_env *env)
{
	int i;
	int w;
	int h;

	i = 0;
	w = 64;
	h = 64;
	env->img[0] = mlx_xpm_file_to_image(env->mlx->mlx_init,
		"textures/1.xpm", &w, &h);
	env->img[1] = mlx_xpm_file_to_image(env->mlx->mlx_init,
		"textures/2.xpm", &w, &h);
	env->img[2] = mlx_xpm_file_to_image(env->mlx->mlx_init,
		"textures/3.xpm", &w, &h);
	env->img[3] = mlx_xpm_file_to_image(env->mlx->mlx_init,
		"textures/4.xpm", &w, &h);
	while (i < 4)
	{
		if (env->img[i] == NULL)
			malloc_error();
		i++;
	}
	get_data_addr(env);
}
