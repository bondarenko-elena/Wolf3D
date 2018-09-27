#include "../includes/wolf3d.h"

void switch_music(int keycode)
{
	if (keycode == SWITCH_MUSIC)
	{
		system("killall mpg123");
		play_music();
	}
	if (keycode == MUTE)
		system("killall mpg123");
}