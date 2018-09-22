#include "../includes/wolf3d.h"

void	play_music(t_env *env)
{
	// if (i == 0)
		// mute
	if (env->switch_music == 1)
		system("afplay ../music/music1.mp3");
	if (env->switch_music == 2)
		system("afplay ../music/music2.mp3");
	if (env->switch_music == 3)
		system("afplay ../music/music3.mp3");
	if (env->switch_music == 4)
		system("afplay ../music/music4.mp3");
}