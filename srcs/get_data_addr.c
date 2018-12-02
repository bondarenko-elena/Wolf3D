/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:51 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	get_data_addr(t_env *env)
{
	env->data[0] = mlx_get_data_addr(env->img[0], &env->bits_per_pixel[0],
		&env->size_line[0], &env->endian[0]);
	env->data[1] = mlx_get_data_addr(env->img[1], &env->bits_per_pixel[1],
		&env->size_line[1], &env->endian[1]);
	env->data[2] = mlx_get_data_addr(env->img[2], &env->bits_per_pixel[2],
		&env->size_line[2], &env->endian[2]);
	env->data[3] = mlx_get_data_addr(env->img[3], &env->bits_per_pixel[3],
		&env->size_line[3], &env->endian[3]);
}
