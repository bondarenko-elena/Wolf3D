#include "../includes/wolf3d.h"

int switch_textures(int keycode)
{
	int	random;

	srand(time(NULL));
	random = rand() % 6 + 1;
	if (keycode == SWITCH_TEXTURES)
		return (random);
	if (keycode == ONE || keycode == ONE_NUMPAD)
		return (1);
	if (keycode == TWO || keycode == TWO_NUMPAD)
		return (2);
	if (keycode == THREE || keycode == THREE_NUMPAD)
		return (3);
	if (keycode == FOUR || keycode == FOUR_NUMPAD)
		return (4);
	if (keycode == FIVE || keycode == FIVE_NUMPAD)
		return (5);
	if (keycode == SIX || keycode == SIX_NUMPAD)
		return (6);
	if (keycode == RESET_TEXTURES)
		return (0);
	return (-1);
}