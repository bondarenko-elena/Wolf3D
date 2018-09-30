/*
afplay is a Mac command which plays audio file, where the last character ''&'' indicates afplay to run in the background as a job.
system("afplay music/music1.mp3 &");
---------------------------------------
mpg123 is analogue for Linux
---------------------------------------
void	play_music()
{
	int	random;

	srand(time(NULL));
	random = rand() % 10 + 1;
	if (random == 1)
		system("mpg123  music/music1.mp3 &");
	if (random == 2)
		system("mpg123  music/music2.mp3 &");
	if (random == 3)
		system("mpg123  music/music3.mp3 &");
	if (random == 4)
		system("mpg123  music/music4.mp3 &");
	if (random == 5)
		system("mpg123  music/music5.mp3 &");
	if (random == 6)
		system("mpg123  music/music6.mp3 &");
	if (random == 7)
		system("mpg123  music/music7.mp3 &");
	if (random == 8)
		system("mpg123  music/music8.mp3 &");
	if (random == 9)
		system("mpg123  music/music9.mp3 &");
	if (random == 10)
		system("mpg123  music/music10.mp3 &");
}
*/

#include "../includes/wolf3d.h"

void	play_music()
{
	int	random;

	srand(time(NULL));
	random = rand() % 10 + 1;
	if (random == 1)
		system("afplay  music/music1.mp3 &");
	if (random == 2)
		system("afplay  music/music2.mp3 &");
	if (random == 3)
		system("afplay  music/music3.mp3 &");
	if (random == 4)
		system("afplay  music/music4.mp3 &");
	if (random == 5)
		system("afplay  music/music5.mp3 &");
	if (random == 6)
		system("afplay  music/music6.mp3 &");
	if (random == 7)
		system("afplay  music/music7.mp3 &");
	if (random == 8)
		system("afplay  music/music8.mp3 &");
	if (random == 9)
		system("afplay  music/music9.mp3 &");
	if (random == 10)
		system("afplay  music/music10.mp3 &");
}