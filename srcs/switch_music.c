#include "../includes/wolf3d.h"

void switch_music(int keycode, t_env *env)
{
	if (keycode == SWITCH_MUSIC)
	{
		system("killall afplay");
		env->music_tumbler = 1;
		play_music();
	}
	if (keycode == MUTE)
		system("killall afplay");
}