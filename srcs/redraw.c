/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:55 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	redraw(t_env *env)
{
	ft_memset(env->mlx->adress, 0, SCREEN_WIDTH * SCREEN_HEIGHT * 4);
	ray_casting(env);
	mlx_put_image_to_window(env->mlx->mlx_init,
		env->mlx->window, env->mlx->image, 0, 0);
	display_text(env);
}
