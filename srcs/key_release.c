/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:52 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		key_release(int keycode, t_env *env)
{
	if (keycode == KEY_UP || keycode == ARROW_UP)
		env->up = 0;
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		env->down = 0;
	if (keycode == ROTATE_LEFT)
		env->rot_left = 0;
	if (keycode == ROTATE_RIGHT)
		env->rot_right = 0;
	if (keycode == KEY_LEFT || keycode == ARROW_LEFT)
		env->left = 0;
	if (keycode == KEY_RIGHT || keycode == ARROW_RIGHT)
		env->right = 0;
	return (0);
}
