/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:52 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	key_press_init(int keycode, t_env *env)
{
	if (keycode == KEY_UP || keycode == ARROW_UP)
		env->up = 1;
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		env->down = 1;
	if (keycode == ROTATE_RIGHT)
		env->rot_right = 1;
	if (keycode == ROTATE_LEFT)
		env->rot_left = 1;
	if (keycode == KEY_LEFT || keycode == ARROW_LEFT)
		env->left = 1;
	if (keycode == KEY_RIGHT || keycode == ARROW_RIGHT)
		env->right = 1;
}
