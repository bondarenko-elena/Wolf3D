/*
afplay is a Mac command which plays audio file, where the last character ''&'' indicates afplay to run in the background as a job.
mpg123 is analogue for Linux
*/

#include "../includes/wolf3d.h"

int	play_music(t_env *env)
{
	if (env->switch_music >= 0 && env->switch_music < 4)
		env->switch_music++;
	if (env->switch_music == 4)
		env->switch_music = 0;
	if (env->switch_music == 0)
	{
		puts("mute music");
	}
	if (env->switch_music == 1)
	{
		// system("afplay ../music/music1.mp3 &");
		system("mpg123  music/music1.mp3 &");
		return (0);
	}
	if (env->switch_music == 2)
	{
		// system("afplay ../music/music2.mp3 &");
		system("mpg123  music/music2.mp3 &");
		return (0);
	}
	if (env->switch_music == 3)
	{
		// system("afplay ../music/music3.mp3 &");
		system("mpg123  music/music3.mp3 &");
		return (0);
	}
	if (env->switch_music == 4)
	{
		// system("afplay ../music/music4.mp3 &");
		system("mpg123  music/music4.mp3 &");
		return (0);
	}
	return (-1);
}