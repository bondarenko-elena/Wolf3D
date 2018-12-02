/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:52 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:42:34 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		key_press(int keycode, t_env *env)
{
	print_keycode(keycode);
	if (keycode == SWITCH_MUSIC)
	{
		env->ray->music_tumbler = 1;
		play_music();
	}
	if (keycode == MUTE)
	{
		env->ray->music_tumbler = 0;
		system("killall -9 afplay");
	}
	if (keycode == SWITCH_TEXTURES)
	{
		env->ray->switch_textures = !env->ray->switch_textures;
		redraw(env);
	}
	if (keycode == KEY_ESC)
	{
		if (env->ray->music_tumbler == 1)
			system("killall -9 afplay");
		exit(0);
	}
	key_press_init(keycode, env);
	return (0);
}
