#include "../includes/wolf3d.h"

void put_pixel(t_env *env, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * env->size_line);
	env->pixel[i] = c;
	env->pixel[++i] = c >> 8;
	env->pixel[++i] = c >> 16;
}