/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:50 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:44:46 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	display_text(t_env *env)
{
	mlx_string_put(env->mlx->mlx_init, env->mlx->window,
			10, 30, 0x7C0A02, "Control keys:");
	mlx_string_put(env->mlx->mlx_init, env->mlx->window,
			10, 45, 0x7C0A02, "Move - arrows or WASD");
	mlx_string_put(env->mlx->mlx_init, env->mlx->window,
			10, 60, 0x7C0A02, "Rotate - Q/E");
	mlx_string_put(env->mlx->mlx_init, env->mlx->window,
			10, 75, 0x7C0A02, "Switch music - M");
	mlx_string_put(env->mlx->mlx_init, env->mlx->window,
			10, 90, 0x7C0A02, "Mute - N");
	mlx_string_put(env->mlx->mlx_init, env->mlx->window,
			10, 105, 0x7C0A02, "Switch on textures - T");
}
