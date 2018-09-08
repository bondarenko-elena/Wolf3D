#include "../includes/wolf3d.h"

void display(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			put_pixel(env, x, y);
			x++;
		}
		y++;
	}
}